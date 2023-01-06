/* eslint-disable max-len */
/* eslint-disable no-unused-vars */
/* eslint-disable react/prop-types */
import React from 'react';
import axios from 'axios';
import _ from 'lodash';
import { Input, message, Button, Modal, Form, Select } from 'antd';
import { NAMESPACE_API, RULES_CRUD_API } from './rules_constants';
import 'antd/lib/message/style/index.css';
import { DROP, EXTRACT, FORWARD, MATCH, VALIDATE_RE2 } from '../../components/event-modal/constants';
import APPLICATION_API from '../../components/dropDown/applications/constants';

const { Item } = Form;
const allowedFields = {
  // name: { type: 'string' },
  description: { allowEmpty: true, type: 'string', fieldType: 'text' },
  // level: { allowEmpty: true, type: 'select' },
  condition: { allowEmpty: true, type: 'string', fieldType: 'text' },
  match: { allowEmpty: false, type: 'string', fieldType: 'text' },
  rewrite: { allowEmpty: false, type: 'string', fieldType: 'string' },
  // groupName: { allowEmpty: true, type: 'select' },
  applicationMatch: { allowEmpty: true, type: 'string', fieldType: 'string' },
};

class EditRuleUnwrapped extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      namespaces: [],
      applications: [],
      currentNamespace: this.props.record.namespace,
      currentApp: this.props.record.applicationMatch,
    };

    if (this.props.record.ruleType === FORWARD) {
      allowedFields.namespace = { allowEmpty: true, type: 'string', fieldType: 'dropdown' };
      allowedFields.applicationMatch = { allowEmpty: true, type: 'string', fieldType: 'dropdown' };
    } else {
      allowedFields.applicationMatch = { allowEmpty: true, type: 'string', fieldType: 'string' };
    }

    if (this.props.record.ruleType === DROP || this.props.record.ruleType === FORWARD) {
      allowedFields.additionalLabels = { allowEmpty: true, type: 'array', fieldType: 'select' };
    } else {
      delete allowedFields.additionalLabels;
    }

    if (this.props.record.ruleType === EXTRACT) {
      allowedFields.patternLabels = { allowEmpty: true, type: 'array', fieldType: 'object' };
    } else {
      delete allowedFields.patternLabels;
    }
  }

  componentDidMount = () => {
    if (this.props.record.ruleType === DROP || this.props.record.ruleType === FORWARD) {
      this.fetchNamespaces();
    }
  }

  onSubmit = (e) => {
    const { isActiveRules } = this.props;
    e.preventDefault();
    const _placeholder = this.props.record.additionalLabels;
    this.props.form.validateFields((err, values) => {
      let store;
      let payload;
      if (!err) {
        const url = `${RULES_CRUD_API}/${this.props.record.name}`;
        if ('additionalLabels' in values) {
          store = Array.isArray(values.additionalLabels) ? values.additionalLabels : [values.additionalLabels];
          delete values.additionalLabels;
          _placeholder.labels = store;
          payload = { ...this.props.record, ...values, ...{ additionalLabels: _placeholder } };
        } else {
          payload = { ...this.props.record, ...values };
        }
        // altering the form submit for pattern labels field
        if (_.has(values, 'patternLabels') && !_.isEmpty(values.patternLabels)) {
          payload.patternLabels = [{ pattern: values.patternLabels }];
        } else if (_.has(values, 'patternLabels') && _.isEmpty(values.patternLabels)) {
          payload.patternLabels = [];
        }
        (async () => {
          try {
            await (await axios.put(url, payload)).data;
            message.success(`${isActiveRules ? 'Rule updated successfully' : 'Event updated successfully'}`);
            this.props.handleCancel();
            this.props.refreshContent();
          } catch (_err) {
            console.error(_err);
            message.error(`Error while updating the ${isActiveRules ? 'rule' : 'event'}`);
            this.props.handleCancel();
          }
        })();
      }
    });
  }

  validatePattern = async (rule, pattern, callback) => {
    let msg;
    if (!_.isEmpty(pattern)) {
      if (pattern && pattern.length < 3) {
        msg = 'Please enter minimum 3 characters';
      } else {
        msg = await this.validateRegex(pattern);
      }
    }
    if (!_.isEmpty(msg)) {
      callback(msg);
    } else {
      callback();
    }
  }

  validateRegex = async (rgxValue) => {
    try {
      const payload = {
        pattern: rgxValue,
      };
      const response = await (await axios.post(VALIDATE_RE2, payload)).data;
      if ('valid' in response) {
        if (!response.valid) {
          return 'Not a valid regex pattern';
        }
        if (response.valid === true) {
          return '';
        }
      } else {
        return `Not a valid regex pattern: ${response.error}`;
      }
    } catch (error) {
      return `Error while validating regex pattern: ${error}`;
    }
  }

  fetchNamespaces = async () => {
    try {
      const response = await (await axios.get(NAMESPACE_API)).data;

      if ('namespaces' in response) {
        const namespaces = response.namespaces.map(ns => ns.namespace);
        this.setState({ namespaces });
      }
      this.fetchApplications(this.props.record.namespace || '');
    } catch (err) {
      message.error('error fetching namespaces');
    }

    return () => {};
  };

   fetchApplications = async (name) => {
     try {
       let url = APPLICATION_API;
       if (name !== '') {
         url += `?namespace=${name}`;
       }

       let apps = await (await axios.get(url, {
       })).data;
       if (apps.applications) {
         apps = Array.from(new Set(apps.applications
           .filter(app => app.namespace === name)
           .sort((a, b) => (a.name > b.name ? 1 : -1))
           .map(ele => ele.name)));
       }

       this.setState({
         applications: [...apps],
       });
     } catch (err) {
       message.error('error fetching applications');
     }

     return () => {};
   }

   onNamespaceChange = (nSpace) => {
     this.setState({
       currentNamespace: nSpace,
     }, () => {
       this.fetchApplications(nSpace);
     });
   }

   onApplicationChange = (appName) => {
     this.setState({
       currentApp: appName,
     });
   }

   updateCondition = () => {
     const { currentNamespace, currentApp } = this.state;
     this.props.record.condition = `(Namespace=='${currentNamespace}') && (AppName=~'${currentApp}')`;
   }

   remderFormItem(field, getFieldDecorator) {
     let _labels = [];
     let _initialValue = this.props.record[field];
     if (field === 'additionalLabels') {
       this.props.record[field].labels = Array.isArray(this.props.record[field].labels) ? this.props.record[field].labels : [this.props.record[field].labels];
       _labels = this.props.record[field].labels;
       if (_labels && _labels.length > 0) {
         _initialValue = _labels[0];
       } else {
         _initialValue = '';
       }
     }
     return (
       <Item
         label={field}
         name={field}
         required={field !== 'additionalLabels'}
         key={field}
       >
         {(this.props.record.ruleType === DROP || this.props.record.ruleType === MATCH || this.props.record.ruleType === FORWARD) && allowedFields[field].fieldType === 'select' && (
           getFieldDecorator(field, {
             rules: [{ required: field !== 'additionalLabels', message: `Please input a valid ${field}` }],
             initialValue: _initialValue,
           })(
             <Select
               showSearch
               mode="tags"
               style={{ width: '100%' }}
               label="select labels"
             >
               {field !== 'additionalLabels' ? this.props.record[field].map(data => (
                 <Select.Option value={data} key={data}>
                   {data}
                 </Select.Option>
               )) : (
                 _labels.map(data => (
                   <Select.Option value={data} key={data}>
                     {data}
                   </Select.Option>
                 ))
               )}
             </Select>,
           )
         )}

         {(allowedFields[field].fieldType === 'text' || allowedFields[field].fieldType === 'string') && (
           getFieldDecorator(field, {
             rules: [{ required: true, message: `Please input a valid ${field}` }],
             initialValue: this.props.record[field],
           })(
             <Input.TextArea
               autoSize
               placeholder={`${field}*`}
             />,
           )
         )}

         {allowedFields[field].fieldType === 'object' && (
           getFieldDecorator(field, {
             rules: [
               // { required: true, message: `Please input a valid ${field}` },
               { validator: this.validatePattern },
             ],
             initialValue: this.props.record[field][0] && this.props.record[field][0].pattern,
           })(
             <Input.TextArea
               autoSize
               placeholder={`${field}*`}
               itemType="tag"
             />,
           )
         )}

         {(this.props.record.ruleType === FORWARD) && (field === 'namespace') && allowedFields[field].fieldType === 'dropdown' && (
           getFieldDecorator(field, {
             rules: [{ required: true, message: `Please input a valid ${field}` }],
             initialValue: this.props.record[field],
           })(
             <Select
               style={{ width: '100%' }}
               label="namespace"
               onChange={this.onNamespaceChange}
             >
               {this.state.namespaces.map(data => (
                 <Select.Option value={data} key={data}>
                   {data}
                 </Select.Option>
               ))}
             </Select>,
           )
         )}
         {(this.props.record.ruleType === FORWARD) && (field === 'applicationMatch') && allowedFields[field].fieldType === 'dropdown' && (
           getFieldDecorator(field, {
             rules: [{ required: true, message: `Please input a valid ${field}` }],
             initialValue: this.props.record[field],
           })(
             <Select
               style={{ width: '100%' }}
               label="applicationMatch"
               onChange={this.onApplicationChange}
             >
               {this.state.applications && this.state.applications.map(data => (
                 <Select.Option value={data} key={data}>
                   {data}
                 </Select.Option>
               ))}
             </Select>,
           )
         )}
       </Item>
     );
   }

   renderFormFields = (filters, includes, getFieldDecorator) => Object.keys(this.props.record)
     .filter(field => (includes ? filters.includes(field) : !filters.includes(field)))
     .filter(
       field => (field === 'applicationMatch' || (field in allowedFields &&
      (this.props.record[field] !== '' || field === 'namespace' && this.props.record.ruleType === FORWARD && this.props.record[field] === '') &&
      this.props.record[field] !== null &&
      this.props.record[field] !== undefined)),
     )
     .map(field => (
       this.remderFormItem(field, getFieldDecorator)
     ))

   render() {
     const { getFieldDecorator } = this.props.form;

     const formItemLayout = {
       labelCol: {
         xs: { span: 24 },
         sm: { span: 4 },
       },
       wrapperCol: {
         xs: { span: 24 },
         sm: { span: 20 },
       },
     };

     return (
       <Modal
         visible={this.props.visible}
         width="75%"
         destroyOnClose
         onCancel={this.props.handleCancel}
         heigth
         title={`${this.props.record.name} (editing)`}
         footer={null}
       >
         <Form
           {...formItemLayout}
           name="logiq-rule-edit"
           className="logiq-rule-edit-form"
           layout="horizontal"
           onSubmit={this.onSubmit}
         >
           {
            this.props.record.ruleType === FORWARD && (
              this.renderFormFields(['namespace'], true, getFieldDecorator))
            }
           {
             this.renderFormFields(['applicationMatch'], true, getFieldDecorator)
            }
           {
             this.renderFormFields(['applicationMatch', 'namespace'], false, getFieldDecorator)
            }
           <Item
             wrapperCol={{ span: 4, offset: 4 }}
           >
             <Button
               type="default"
               htmlType="submit"
             >
               Update
             </Button>
           </Item>
         </Form>
       </Modal>
     );
   }
}

const EditRuleModal = Form.create({ name: 'forwarder_create' })(EditRuleUnwrapped);

export default EditRuleModal;


// export default EditRuleModal;
