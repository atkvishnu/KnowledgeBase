/* eslint-disable no-use-before-define */
/* eslint-disable react/prop-types */
/* eslint-disable no-unused-vars */
/* eslint-disable no-console */
import React from 'react';
import axios from 'axios';
import _ from 'lodash';
import { Col, Divider, Icon, Input, message, Radio, Row, Select, Switch, Tooltip } from 'antd';
import moment from 'moment';
import LEVEL_FILTER_OPTIONS from '../dropDown/levels/constants';
import EventFieldRenderer from './EventFieldRenderer';
import StructuredData from './StructuredData';

import {
  DROP,
  EXTRACT,
  FORWARD,
  GROUPS_API,
  HELP_CUSTOM_RENAME_LABELS,
  HELP_DROP_LABELS,
  HELP_FORWARD_LABELS,
  HELP_RENAME_LABELS,
  MATCH,
  NO_NAME_CAPTURE_GROUP,
  REWRITE,
  RULES_TYPE,
  SIEM,
  TAGS,
  VALIDATE_RE2,
  VALIDATE_RULE_NAME,
} from './constants';
import 'antd/lib/message/style/index.css';
import AdvanceSearch from '../searchAutoComplete/AdvanceSearch';
import SyntaxHighlight from '../syntaxHighlight';
import Applications from '../dropDown/applications/applications';

const REGEX = /^[-+]?\d+[.]+\d+$/gm;

const EventRule = ({ log,
  handleAlert,
  eventDescription,
  setEventDescription,
  eventFields,
  setEventFields,
  handleAdditionalLabels,
  handleRenamedLabels,
  handleCustomRenamedLabels,
  handleTags,
  uniqueName,
  setUniqueName,
  handleEventFieldsQuery,
  fieldsQuery,
  additionalNamespaces,
  setGroupByLabel,
  setPatternLabels,
  patternLabels,
  labelsMode = 'multiple',
  handleRuleType,
  queryCondition,
  eventPeriod,
  operator,
  occurances,
  rearm,
  refresh,
  until,
  untilDate,
  rType,
  handleEnableDropLabelsChange,
  bundleType,
  additionalProps }) => {
  const [eventGroups, setEventGroups] = React.useState([]);
  const [eventCopy, setEventCopy] = React.useState({});
  const [eventGroupLoading, setEventGroupLoading] = React.useState(true);
  const [structuredData, setStructuredData] = React.useState([]);
  const [structureDataCount, setStructureDataCount] = React.useState(0);
  const [additionalFields, setAdditionalFields] = React.useState({});
  const [additionalLabels, setAdditionalLabels] = React.useState([]);
  const [tags, setTags] = React.useState([]);
  const [selectedTags, setSelectedTags] = React.useState([]);
  const [labels, setLabels] = React.useState([]);
  const [selectedLabel, setSelectedLabel] = React.useState('');
  const [namespaces, setNamespaces] = React.useState([]);
  const [currentNamespace, setCurrentNamespace] = React.useState();
  const [patterns, setPatterns] = React.useState([]);
  const [ruleType, setRuleType] = React.useState(rType || MATCH);
  const [ruleName, setRuleName] = React.useState('');
  const [enableDropLabels, setEnableDropLabels] = React.useState(false);
  const [advanceQueryFields, setAdvanceQueryFields] = React.useState({});
  const [switchKey, setSwitchKey] = React.useState(Math.random().toString(36).substring(7));
  const [enableRenameLabels, setEnableRenameLabels] = React.useState(false);
  const [renamedSelectedLabelsStore, setRenamedSelectedLabelsStore] = React.useState([]);
  const [enableCustomRenameLabels, setEnableCustomRenameLabels] = React.useState(false);
  const [customLabelsSelectedStore, setCustomLabelsSelectedStore] = React.useState([]);
  const [customRenamedLabelsStore, setCustomRenamedLabelsStore] = React.useState([]);
  React.useEffect(() => {
    setLabels(patternLabels);
  }, [patternLabels]);

  React.useEffect(() => {
    (async () => {
      try {
        const groups = (await (await axios.get(GROUPS_API)).data).groupNames;
        if (!groups.includes(bundleType)) {
          groups.push(bundleType);
        }
        const groupValues = groups.map(name => ({ label: name, value: name }));
        setEventGroups(groupValues);
        setEventGroupLoading(false);
        handleGroupLabel(bundleType);
      } catch (error) {
        console.error(error);
        throw new Error(error);
      }
    })();


    (async () => {
      try {
        const response = (await (await axios.get(TAGS)).data).tags;
        const _tags = response.map(tag => ({ value: tag.name, label: tag.name }));
        setTags(_tags);
      } catch (error) {
        console.error(error);
        throw new Error(error);
      }
    })();
  }, []);

  React.useEffect(() => {
    setEventCopy({ ...eventFields });
  }, [eventFields]);

  React.useEffect(() => {
    const tempAdditionalFields = { ...additionalFields };
    Object.keys(eventFields).forEach((field) => {
      if (eventFields[field].collapse === true) {
        tempAdditionalFields[field] = [eventFields[field].text];
        // tempAdditionalFields.push({
        //   key: field,
        //   value: [eventFields[field].text],
        // });
      }
    });
    setAdditionalFields(tempAdditionalFields);
  }, [eventFields]);

  React.useEffect(() => {
    if (additionalNamespaces.length > 0) {
      setNamespaces(additionalNamespaces);
      const _currentNamespace = additionalNamespaces[0];
      // // setCurrentNamespace(_currentNamespace);
      // // handleFieldText('Namespace==', additionalNamespaces[0]);
      // const tempEventFields = { ...eventFields };
      // tempEventFields.Namespace.text = `Namespace==${_currentNamespace}`; // _currentNamespace;
      // console.log(tempEventFields);
      // setEventFields(tempEventFields);
    }
  }, [additionalNamespaces]);

  React.useEffect(() => {
    if (additionalProps) {
      handlePatternProps();
    }
  }, [additionalProps]);

  const handlePatternProps = () => {
    const _eventFields = { ...eventFields };
    const { namespace, applications, psid } = additionalProps;
    _eventFields.Namespace.text = `Namespace=~${namespace}`;
    _eventFields.ApplicationMatch.text = applications[0];

    setNamespaces([namespace]);
    setCurrentNamespace(namespace);
    setEventFields({ ..._eventFields });

    const keys = Object.keys(fieldsQuery);
    const index = keys.length > 0 ? (Math.max(...keys) + 1) : 1;
    fieldsQuery[index] = { 1: {
      currentField: 'Psid',
      searchValue: psid,
      operator: '==',
    } };
    setAdvanceQueryFields(fieldsQuery);

    handleEventFieldsQuery(fieldsQuery);
  };


  const onLogChange = () => {
    const tempEventFields = { ...eventFields };
    const fields = Object.keys(eventFields);
    Object.keys(log).forEach((key) => {
      if (fields.includes(key)) {
        tempEventFields[key].text = `${key}=='${log[key]}'`;
      }
    });
    if ('AppName' in log) {
      tempEventFields.ApplicationMatch.text = log.AppName;
    }
    delete tempEventFields.AppName;
    setEventFields(tempEventFields);

    if ('StructuredData' in log && log.StructuredData.length > 0) {
      const _filtered = log.StructuredData.filter(data => data.values[0].match(REGEX) !== null);
      const _stringFiltered = [];
      log.StructuredData.forEach((d) => {
        // if (d.values[0].match(NUMERIC_ONLY_REGEX) === null) {
        //   _stringFiltered.push(d);
        // }
        // if (d.key.match(ALLOWED_REGEX) !== null) {
        //   _stringFiltered.push(d);
        // }
        _stringFiltered.push(d);
      });

      const __labels = [..._stringFiltered].filter(label => label.key !== '_event');
      setLabels(__labels);
      if (_filtered.length > 0) {
        const _keys = _filtered.map(d => d.key);
        const _labels = __labels.filter(d => _keys.indexOf(d.key) < 0);
        setLabels(_labels);
      }
      const _tmp = log.StructuredData.map(data => ({ name: data.key, value: data.key }));

      setStructureDataCount(log.StructuredData.length);
      const tempStructuredData = {};
      log.StructuredData.forEach((data) => {
        tempStructuredData[data.key] = { values: data.values,
          added: false,
          id: Math.random().toString(36).substring(7) };
      });
      // setStructuredData(tempStructuredData);
    }
  };

  React.useEffect(() => {
    onLogChange();
  }, [log]);
  // const onCancel = () => setVisible(false);
  const allowedInput = [
    // 'Message',
    // 'AppName',
    // 'SeverityString',
    // 'FacilityString',
    // 'Sender'
  ];

  React.useEffect(() => {
    setAdditionalLabels([]);
    setEnableDropLabels(false);
    if ((rType === MATCH || rType === SIEM || rType === DROP || rType === FORWARD)) {
      onLogChange();
    }
    if (rType === DROP || rType === FORWARD) {
      setSwitchKey(Math.random().toString(36).substring(7));
    }
    // setCurrentNamespace('');
    if (currentNamespace && currentNamespace !== '') {
      handleNamespaceChange(currentNamespace);
    }
  }, [rType]);


  const handleFieldText = (label, value, trim = true) => {
    const tempEventFields = { ...eventFields };
    tempEventFields[label].text = trim ? value.trim() : value;
    setEventFields(tempEventFields);
  };

  const validateUniqueName = async (e) => {
    const name = e.target.value;
    if (name.trim() !== '') {
      const url = `${VALIDATE_RULE_NAME}/${name}`;

      try {
        const response = await (await axios.get(url)).data;
        if (response.exists) {
          message.error(`An event with the name "${name}" already exists, please choose a different name`);
          setUniqueName(false);
        } else {
          setUniqueName(true);
        }
      } catch (err) {
      // console.log('err: ', err.Message);
        console.error(err);
        setUniqueName(false);
      }
    }
  };


  const handleLevelLabel = (value) => {
    const tempEventDescription = { ...eventDescription };
    tempEventDescription.level = value;
    setEventDescription(tempEventDescription);
  };

  const handleNameLabel = (e) => {
    const tempEventDescription = { ...eventDescription };
    // tempEventDescription.name = e.target.value.replace(/\W+/g, '_');
    const tempName = e.target.value.replace(/\W+/g, '_');
    tempEventDescription.name = tempName;
    setEventDescription(tempEventDescription);
    handleAlert(e);
    setRuleName(tempName);

    // validateUniqueName(e);
  };


  const handleNamespaceChange = (value) => {
    // console.log(value);
    // setNamespaces(event.target.value);
    setCurrentNamespace(value);
    updateNamespaceCondition(value);
  };

  const updateNamespaceCondition = (value) => {
    handleFieldText('Namespace', `Namespace=='${value}'`);
    const tempEventDescription = { ...eventDescription };
    tempEventDescription.namespace = value;
    setEventDescription(tempEventDescription);
  };


  const handleGroupSearch = (value) => {
    const tempEventDescription = { ...eventDescription };
    const tempEventGroups = [...eventGroups];
    if (!tempEventGroups.includes(value)) {
      tempEventGroups.unshift({ value,
        label: (
          <React.Fragment>
            <span> create new group <strong>{value}</strong></span>
          </React.Fragment>) });
    }
    setEventGroups(tempEventGroups);
    tempEventDescription.groupName += value;
    // setEventGroups
    setEventDescription(tempEventDescription);
  };


  const handleGroupLabel = (value) => {
    const tempEventDescription = { ...eventDescription };
    tempEventDescription.groupName = value;
    setEventDescription(tempEventDescription);
  };


  const handleDescriptionLabel = (e) => {
    const tempEventDescription = { ...eventDescription };
    tempEventDescription.description = e.target.value;
    setEventDescription(tempEventDescription);
    handleAlert(e);
  };


  // const handleFieldText = (label, value) => {
  //   const tempEventFields = { ...eventFields };
  //   tempEventFields[label].text = value.trim();
  //   setEventFields(tempEventFields);
  // };


  const handleEventRenderSelect = (label, value) => {
    const tempEventFields = { ...eventFields };
    tempEventFields[label].operator = value;
    setEventFields(tempEventFields);
  };


  const handleEventRenderText = (label, value) => {
    const tempEventFields = { ...eventFields };
    tempEventFields[label].checked = value;
    setEventFields(tempEventFields);
  };


  const handleStructureDataChange = (structureObject) => {
    if ('key' in structureObject &&
    (structureObject.key !== '' || structureObject.key !== undefined)) {
      const key = structureObject.key; // replace(/\./g, '__');
      const tempEventFields = { ...eventFields };
      tempEventFields[key] = {
        text: structureObject.value,
        operator: structureObject.operator,
        checked: true,
        type: structureObject.key in eventCopy ? 'event' : 'structured', // type is added for  filtering and validating it differently

      };

      setEventFields(tempEventFields);
    }
  };

  const handleStructureDataDelete = (idx, structureObject) => {
    if (Object.keys(structureObject).length > 0 &&
    'key' in structureObject &&
    (structureObject.key !== '' || structureObject.key !== undefined)) {
      const tempEventFields = { ...eventFields };
      const key = structureObject.key; // replace(/\./g, '__');
      console.log('deleting state...', key);
      tempEventFields[key] = {
        text: structureObject.value,
        operator: structureObject.operator,
        checked: false,
        type: structureObject.key in eventCopy ? 'event' : 'structured', // type is added for  filtering and validating it differently

      };
      setEventFields(tempEventFields);
    }
  };


  const addStructuredData = () => {
    const tempStructuredData = [...structuredData];
    const count = tempStructuredData.length;
    tempStructuredData.push(
      <React.Fragment>
        <StructuredData
          data={[
            ...Object.entries(additionalFields).map(pair => ({ key: pair[0], values: pair[1], type: 'event' })),
            ...log.StructuredData]}
          handleChange={handleStructureDataChange}
          handleDelete={handleStructureDataDelete}
          eventFields={eventFields}
          idx={count}
        />
        <br />
      </React.Fragment>,


    );
    setStructuredData(tempStructuredData);
  };


  const handleLabelSearch = async (value) => {
    if (!labels.includes(value.trim())) {
      if (value.length >= 3) {
        console.log('search: ', value);
        // Finding the param labesl
        try {
          const payload = {
            message: log.Message,
            pattern: value,
          };
          const response = await (await axios.post(VALIDATE_RE2, payload)).data;
          if ('valid' in response) {
            if (response.valid === true) {
              if (Object.keys(response.matchedData).length > 0) {
                const patternLabel = {
                  pattern: value,
                  matchedNames: response.names,
                };
                message.success(`Pattern (${value}), found following matches: ${JSON.stringify(response.names)}`);
                const _tmpPatternLabels = [...patterns];
                setPatterns(_tmpPatternLabels);

                _tmpPatternLabels.push(patternLabel);
                setPatternLabels(_tmpPatternLabels);
                const _tmpLabels = [...labels];
                if (_tmpLabels.filter(label => label.key === value).length === 0) {
                  _tmpLabels.push({ key: value, value });
                  setLabels(_tmpLabels);
                }

                // return true;
              } else {
                message.error(NO_NAME_CAPTURE_GROUP);
              }
            } else {
              message.error(`Not a valid regex pattern: ${response.error}`);
            }
          }
        } catch (error) {
          message.error(`Error while validating regex pattern: ${error}`);
        }
      }
    }

    // return false;
  };

  const selectAdditionalLabels = async (value) => {
    // console.log('changing: ', value);
    // console.log(labels.includes(value));
    // console.log("labels--------->", labels)
    if (typeof value === 'string') {
      value = [value];
    }
    handleAdditionalLabels(value);
    setAdditionalLabels(value);
  };

  /**
   * This method validates the regex pattern, and then sets pattern.
   * @param {} rgxValue
   * @returns
   */
  const validateRegexPattern = async (rgxValue) => {
    if (!labels.includes(rgxValue.trim())) {
      if (rgxValue.length >= 3) {
        try {
          const payload = {
            pattern: rgxValue,
          };
          const response = await (await axios.post(VALIDATE_RE2, payload)).data;
          if ('valid' in response) {
            if (!response.valid) {
              message.error('Not a valid regex pattern');
            } else {
              if (response.valid === true) {
                const patternLabel = {
                  pattern: rgxValue,
                };
                const _tmpPatternLabels = [...patterns];
                setPatterns(_tmpPatternLabels);

                // Checking if pattern has regex value.
                const hasPattern = _tmpPatternLabels.filter(pl => pl.pattern === rgxValue).length > 0;
                if (!hasPattern) {
                  _tmpPatternLabels.push(patternLabel);
                }

                setPatternLabels(_tmpPatternLabels);
                const _tmpLabels = [...labels];
                if (_tmpLabels.filter(label => label.key === rgxValue).length === 0) {
                  _tmpLabels.push({ key: rgxValue, value: rgxValue });
                  setLabels(_tmpLabels);
                }

                return true;
              }
            }
          } else {
            message.error(`Not a valid regex pattern: ${response.error}`);
          }
        } catch (error) {
          message.error(`Error while validating regex pattern: ${error}`);
        }
      }
    }

    return false;
  };


  /**
   * This function handles the label change for EXTRACT rule type.
   * Using the additional labels field.
   *
   * @param {} value
   */
  const handleLabelChange = async (value) => {
    const isValidRegex = await validateRegexPattern(value);

    if (typeof value === 'string') {
      value = [value];
    }

    handleAdditionalLabels(value);
    setAdditionalLabels(value);
  };


  const addTags = (value) => {
    setSelectedTags(value);
    handleTags(value);
  };

  const handleTagSearch = (value) => {
    const _tmp = tags.map(tag => tag.label);
    const _tmpTags = [...tags];
    if (!_tmp.includes(value)) {
      _tmpTags.unshift({ value,
        label: (
          <React.Fragment>
            <span> add new tag <strong>{value}</strong></span>
          </React.Fragment>) });
    }
    setTags(_tmpTags);
  };

  const getLogKeys = () => {
    const dd = Object.entries(additionalFields).map(pair => ({ key: pair[0], values: pair[1], type: 'event' }));
    const _fields = {};
    if (dd) {
      dd.forEach((d) => {
        _fields[d.key] = { values: [], type: 'event', defaultOperator: '=~' };
      });
    }
    if (log.StructuredData) {
      log.StructuredData.forEach((s) => {
        _fields[s.key] = { values: [], type: 'structured', defaultOperator: '=~' };
      });
    }

    return _fields;
  };

  const handleAdvanceEventsQuery = (query) => {
    setAdvanceQueryFields(query);
    handleEventFieldsQuery(query);
  };


  const selectGroupByLabel = (value) => {
    setSelectedLabel(value);
    setGroupByLabel(value);
  };

  const handleRuleTypeChange = (event) => {
    setRuleType(event.target.value);
    handleRuleType(event.target.value);
    if (event.target.value === 'REWRITE') {
      eventFields.Match.text = '';
      eventFields.Rewrite.text = '';
    }
  };

  const enableDropLabelsChange = (enable) => {
    setEnableDropLabels(enable);
    handleEnableDropLabelsChange(enable);
    if (!enable) {
      handleAdditionalLabels([]);
    } else {
      handleAdditionalLabels([...additionalLabels]);
    }
  };

  const enableRenameRuleChange = (enable) => {
    setEnableRenameLabels(enable);
    if (!enable) {
      handleAdditionalLabels([]);
    } else {
      handleAdditionalLabels([...additionalLabels]);
    }
  };

  const handleRenameChange = value => (event) => {
    const data = { ...renamedSelectedLabelsStore };
    // data[index] = `"${value}": "${event.target.value}"`;
    data[value] = `${event.target.value}`;
    setRenamedSelectedLabelsStore(data);
    handleRenamedLabels(data);
  };

  const enableCustomRenameLabelsChange = () => {
    setEnableCustomRenameLabels(!enableCustomRenameLabels);
  };

  const handleCustomRenameLabelsChange = (selection) => {
    if (typeof selection === 'string') {
      selection = [selection];
    }
    setCustomLabelsSelectedStore(selection);
    handleCustomRenamedLabels(selection);
  };

  const handleCustomRenameChange = value => (event) => {
    const data = { ...customRenamedLabelsStore };
    data[value] = `${event.target.value}`;
    setCustomRenamedLabelsStore(data);
    handleCustomRenamedLabels(data);
  };

  const getDropLabelsView = () => (
    <React.Fragment>
      <Row>
        <Col xs={8} sm={8} md={8} lg={8} xl={8}>
          {
            rType === FORWARD ? 'Forward Labels' : 'Enable Drop Labels'
          }
        </Col>
        <Col xs={16} sm={16} md={16} lg={16} xl={16}>
          <Switch key={switchKey} defaultChecked={enableDropLabels} onChange={enableDropLabelsChange} />
        </Col>
      </Row>
      <br />
      { enableDropLabels && (
        <Row>
          <Col xs={8} sm={8} md={8} lg={8} xl={8}>
            {rType === FORWARD ? 'Labels To Forward' : 'Labels To Drop*'}
            <span style={{
              marginLeft: '2%',
            }}
            >
              <Tooltip title={rType === FORWARD ? HELP_FORWARD_LABELS : HELP_DROP_LABELS}>
                <Icon type="question-circle" />
              </Tooltip>
            </span>
          </Col>
          <Col xs={16} sm={16} md={16} lg={16} xl={16}>
            <Select
              showSearch
              mode="tags"
              style={{ width: '100%' }}
              label="select labels"
              onChange={selectAdditionalLabels}
              value={additionalLabels}
            >
              {
                labels.map(data => (
                  <Select.Option value={data.key} key={data.key}>
                    {data.key}
                  </Select.Option>
                ))
              }
            </Select>
          </Col>
        </Row>
      )}
    </React.Fragment>
  );

  const renameRule = () => (
    <React.Fragment>
      <br />
      <Row>
        <Col xs={8} sm={8} md={8} lg={8} xl={8}>
          Rename Forward labels
          <span style={{
            marginLeft: '2%',
          }}
          >
            <Tooltip title={HELP_RENAME_LABELS}>
              <Icon type="question-circle" />
            </Tooltip>
          </span>
        </Col>
        <Col xs={16} sm={16} md={16} lg={16} xl={16}>
          <Switch key={switchKey} defaultChecked={enableRenameLabels} onChange={enableRenameRuleChange} />
        </Col>
      </Row>
      <br />
      { enableDropLabels &&
        enableRenameLabels &&
        (
          additionalLabels.map(data => (
            <span key={data}>
              <Row>
                <Col xs={8} sm={8} md={8} lg={8} xl={8}>
                  {data}
                </Col>
                <Col xs={10} sm={10} md={10} lg={10} xl={10}>
                  <Input
                    allowClear
                    placeholder="Rename to..."
                    name={data}
                    label={data}
                    onChange={handleRenameChange(data)}
                    required
                  />
                </Col>
              </Row>
              &nbsp;
            </span>
          ))
        )
      }
    </React.Fragment>
  );

  const addCustomRenameLabels = () => (
    <React.Fragment>
      <Divider />
      <Row>
        <Col xs={8} sm={8} md={8} lg={8} xl={8}>
          Rename Custom Labels
          <span style={{
            marginLeft: '2%',
          }}
          >
            <Tooltip title={HELP_CUSTOM_RENAME_LABELS}>
              <Icon type="question-circle" />
            </Tooltip>
          </span>
        </Col>
        <Col xs={16} sm={16} md={16} lg={16} xl={16}>
          <Switch key={switchKey} defaultChecked={enableCustomRenameLabels} onChange={enableCustomRenameLabelsChange} />
        </Col>
      </Row>
      <br />
      { enableCustomRenameLabels && (
        <Row>
          <Col xs={8} sm={8} md={8} lg={8} xl={8}>
            Custom Labels to Rename
          </Col>
          <Col xs={16} sm={16} md={16} lg={16} xl={16}>
            <Select
              showSearch
              mode="tags"
              style={{ width: '100%' }}
              label="select custom labels"
              onChange={handleCustomRenameLabelsChange}
              value={customLabelsSelectedStore}
            >
              {
                labels.map(data => (
                  <Select.Option value={data.key} key={data.key}>
                    {data.key}
                  </Select.Option>
                ))
              }
            </Select>
          </Col>
        </Row>
      )
      }
      <br />
      { enableCustomRenameLabels &&
        (
          customLabelsSelectedStore.map(data => (
            <span key={data}>
              <Row>
                <Col xs={8} sm={8} md={8} lg={8} xl={8}>
                  {data}
                </Col>
                <Col xs={10} sm={10} md={10} lg={10} xl={10}>
                  <Input
                    allowClear
                    placeholder="Rename to..."
                    name={data}
                    label={data}
                    onChange={handleCustomRenameChange(data)}
                    required
                  />
                </Col>
              </Row>
              &nbsp;
            </span>
          ))
        )
      }
    </React.Fragment>
  );

  const onApplicationChange = (apps) => {
    handleFieldText('ApplicationMatch', apps[0]);
  };

  const renderApplications = () => (
    <Applications
      key="rule-app"
      onApplicationChange={onApplicationChange}
      defaultApplications={[eventFields.ApplicationMatch.text]}
      nsFilter={eventDescription.namespace}
      fromTime={moment().unix()}
      validateLastSeen={false}
      mode="default"
      maxItem={3}
    />
  );

  return (
    <Row>


      <Col
        xs={24}
        sm={24}
        md={20}
        lg={24}
        xl={24}
        className="event-modal-alert"
      >
        <Row type="flex" justify="center">
          <Col xs={8} sm={8} md={8} lg={8} xl={8}>Rule Type</Col>
          <Col xs={16} sm={16} md={16} lg={16} xl={16}>
            <Radio.Group
              value={ruleType}
              onChange={handleRuleTypeChange}
              // buttonStyle="solid"
              className="logiq-rule-type-group"
            >

              {
                RULES_TYPE.map(rule => (
                  <Radio.Button
                    value={rule.ruleType}
                    className={rule.className}
                  >
                    <Tooltip
                      title={rule.title}
                    >
                      {rule.name}
                    </Tooltip>
                  </Radio.Button>
                ))
                }
            </Radio.Group>
          </Col>
        </Row>
        <br />
        { log.Message && (
          <React.Fragment>
            <Row>
              <Col span={8}>Message</Col>
              <Col span={16}>
                <SyntaxHighlight
                  code={log.Message}
                  language="bash"
                />
              </Col>
            </Row>
            <br />
          </React.Fragment>
        )}
        <Row type="flex" justify="center">
          <Col xs={8} sm={8} md={8} lg={8} xl={8}>Name*</Col>
          <Col xs={16} sm={16} md={16} lg={16} xl={16}><Input
            placeholder="name for the event"
            name="name"
            label="name"
            onChange={handleNameLabel}
            value={eventDescription.name}
            onBlur={validateUniqueName}
            maxLength={180}
            className={`lq-event-name-${uniqueName}`}
          />
          </Col>

        </Row>
        <br />
        {
          [SIEM, MATCH].includes(ruleType) && (
            <React.Fragment>
              <Row>
                <Col xs={8} sm={8} md={8} lg={8} xl={8}>Level*</Col>
                <Col xs={16} sm={16} md={16} lg={16} xl={16}>
                  <Select
                    showSearch
                    style={{ width: '100%' }}
                    label="select level"
                    onChange={handleLevelLabel}
                    value={eventDescription.level}
                  >
                    {
                  LEVEL_FILTER_OPTIONS.map(level => (
                    <Select.Option value={level} key={level}>
                      {level}
                    </Select.Option>
                  ))
                }
                  </Select>
                </Col>
              </Row>

              <br />
            </React.Fragment>
          )
        }

        <Row>
          <Col span={8}>Group*</Col>
          <Col span={16}>
            <Select
              showSearch
              onSearch={handleGroupSearch}
              style={{ width: '100%' }}
              label="level"
              onChange={handleGroupLabel}
              loading={eventGroupLoading}
              value={eventDescription.groupName}
            >
              {
                eventGroups.map(group => (
                  <Select.Option value={group.value} key={group.value}>
                    {group.label}
                  </Select.Option>
                ))
              }
            </Select>
          </Col>
        </Row>
        <br />
        <Row>
          <Col span={8}>Description*</Col>
          <Col span={16}>
            <Input
              placeholder="description for the event"
              label="description"
              maxLength={250}
              onChange={handleDescriptionLabel}
              value={eventDescription.description}
            />
          </Col>
        </Row>
        <br />

        <Row>
          <Col span={8}>Namespace*</Col>
          <Col span={16}>
            {
            namespaces.length > 0 ? (
              <Select
                showSearch
              // onSearch={handleGroupSearch}
                style={{ width: '100%' }}
                label="namespaces"
                onChange={handleNamespaceChange}
              // loading={eventGroupLoading}
                value={currentNamespace !== '' && currentNamespace}
                placeholder="Please select namespace"
              >
                {
                  namespaces.map(ns => (
                    <Select.Option value={ns} key={ns}>
                      {ns}
                    </Select.Option>
                  ))
                }
              </Select>
            ) : (
              <Input
                disabled
                label="namespace"
            // value={namespace}
            // onChange={handleNamespaceChange}
                onChange={e => handleFieldText('Namespace', e.target.value)}
                value={eventFields.Namespace.text}
              />
            )
          }

          </Col>
        </Row>
        <br />


        <Row>
          <Col span={8}>
            ApplicationMatch*
            <span style={{
              marginLeft: '2%',
            }}
            >
              <Tooltip title="A regex to match the application logs where this rule will be applied">
                <Icon type="question-circle" />
              </Tooltip>
            </span>
          </Col>
          <Col span={16}>
            {
              ruleType === FORWARD && (
                renderApplications()
              )
            }
            {
              ruleType !== FORWARD && (
              <Input
                placeholder="application match field, could be a regex expression as well"
                onChange={e => handleFieldText('ApplicationMatch', e.target.value)}
                value={eventFields.ApplicationMatch.text}
              />
              )
            }
          </Col>
        </Row>
        <br />

        {
        ruleType === REWRITE && (
          <React.Fragment>
            <Row>
              <Col span={8}>
                Match
                <span style={{
                  marginLeft: '2%',
                }}
                >
                  <Tooltip title="A regex to match in logs">
                    <Icon type="question-circle" />
                  </Tooltip>
                </span>
              </Col>
              <Col span={16}>
                <Input
                  placeholder="Match, could be a regex expression as well"
                  onChange={e => handleFieldText('Match', e.target.value, false)}
                  value={eventFields.Match ? eventFields.Match.text : ''}
                />
              </Col>
            </Row>
            <br />
            <Row>
              <Col span={8}>
                Rewrite
                <span style={{
                  marginLeft: '2%',
                }}
                >
                  <Tooltip title="A regex to rewrite in logs">
                    <Icon type="question-circle" />
                  </Tooltip>
                </span>
              </Col>
              <Col span={16}>
                <Input
                  placeholder="Rewrite could be a regex expression as well"
                  onChange={e => handleFieldText('Rewrite', e.target.value, false)}
                  value={eventFields.Rewrite ? eventFields.Rewrite.text : ''}
                />
              </Col>
            </Row>
            <br />
          </React.Fragment>
        )
      }

        {
          Object.keys(eventFields)
            .filter(key => allowedInput.includes(key))
            .map(key => (
              <EventFieldRenderer
                label={key}
                key={key}
                defaultValue={eventFields[key].text}
                handleFieldText={handleFieldText}
                handleSelect={handleEventRenderSelect}
                onChange={handleEventRenderText}
                defaultChecked={eventFields[key].checked}
                defaultOperator={eventFields[key].operator}
                writable={eventFields[key].writable}
              />
            ))
          }

        <Row>
          <Col
            span={24}
            style={{
              textAlign: 'center',
            }}
          >
            <AdvanceSearch
              showModal
              handleOk={(e) => { }}// Ignoring the callback
              handleCancel={(e) => { }}// Ignoring the callback
              handleQuery={(e) => { }}// Ignoring the callback
              handleSearchQueryObj={handleAdvanceEventsQuery}
              fields={getLogKeys()}
              searchQueryObj={advanceQueryFields}
              withOutModal
              buttonLabel="+ Add more parameters"
              buttonWidth="35%"
              nameSpace={eventFields.Namespace ? eventFields.Namespace.text : ''}
              applications={eventFields.ApplicationMatch ? [eventFields.ApplicationMatch.text] : []}
            />
          </Col>
        </Row>

        <br />
        {
          ruleType === EXTRACT && (
            <Row>
              <Col xs={8} sm={8} md={8} lg={8} xl={8}>
                Pattern
                <span style={{
                  marginLeft: '2%',
                }}
                >
                  <Tooltip title="Enter the valid regex pattern. RE2 regex supported.">
                    <Icon type="question-circle" />
                  </Tooltip>
                </span>
              </Col>
              <Col xs={16} sm={16} md={16} lg={16} xl={16}>
                <Input
                  placeholder="Regex expression"
                  onChange={e => handleLabelChange(e.target.value)}
                  value={additionalLabels && additionalLabels.length > 0 ? additionalLabels[0] : ''}
                />
              </Col>
            </Row>
          )
        }

        {
          (ruleType === DROP || ruleType === FORWARD) && (
            getDropLabelsView()
          )
        }

        {
          (ruleType === FORWARD) && (
            renameRule()
          )
        }
        {
          (ruleType === FORWARD) && (
            addCustomRenameLabels()
          )
        }
        {
        (ruleType === MATCH || ruleType === SIEM) && (
        <React.Fragment>
          {
        labelsMode === 'tags' ? (
          <Row>
            <Col xs={8} sm={8} md={8} lg={8} xl={8}>
              Labels
              <span style={{
                marginLeft: '2%',
              }}
              >
                <Tooltip title="Select labels to differentiate metric data. Arbitrary tags are supported here.">
                  <Icon type="question-circle" />
                </Tooltip>
              </span>
            </Col>
            <Col xs={16} sm={16} md={16} lg={16} xl={16}>
              <Select
                showSearch
                mode="tags"
                style={{ width: '100%' }}
                label="select labels"
                onChange={selectAdditionalLabels}
                value={additionalLabels}
              >
                {
                    labels.map(data => (
                      <Select.Option value={data.key} key={data.key}>
                        {data.key}
                      </Select.Option>
                    ))
                    }
              </Select>
              <div className="lq-warning-label">
                ** high cardinality will cause increased usage of system resources
              </div>
            </Col>
          </Row>
        ) :

          (
            <Row>
              <Col xs={8} sm={8} md={8} lg={8} xl={8}>
                Labels
                <span style={{
                  marginLeft: '2%',
                }}
                >
                  <Tooltip title="Select labels to differentiate metric data. RE2 regex supported. Each regex should return in single match.">
                    <Icon type="question-circle" />
                  </Tooltip>
                </span>
              </Col>
              <Col xs={16} sm={16} md={16} lg={16} xl={16}>
                <Select
                  showSearch
                  mode="default"
                  style={{ width: '100%' }}
                  label="select labels"
                  onChange={selectAdditionalLabels}
                  value={additionalLabels}
                  onSearch={handleLabelSearch}
                >
                  {
                    labels.map(data => (
                      <Select.Option value={data.key} key={data.key}>
                        {data.key}
                      </Select.Option>
                    ))
                    }
                </Select>

              </Col>
            </Row>
          )
          }
          <br />
          <Row>
            <Col xs={8} sm={8} md={8} lg={8} xl={8}>
              Label for Visualization
              <span style={{
                marginLeft: '2%',
              }}
              >
                <Tooltip title="Select one label to plot the default visualization.
            Additional labels would be present to edit/modify existing graph or to create new graphs."
                >
                  <Icon type="question-circle" />
                </Tooltip>
              </span>

            </Col>
            <Col xs={16} sm={16} md={16} lg={16} xl={16}>
              <Select
                showSearch
                mode="default"
                style={{ width: '100%' }}
                label="select label to group by"
                onChange={selectGroupByLabel}
                value={selectedLabel}
              >
                {
                  additionalLabels.map(data => (
                    <Select.Option value={data} key={data}>
                      {data}
                    </Select.Option>
                  ))
                }
              </Select>

            </Col>
          </Row>

          <br />
          <Row>
            <Col xs={8} sm={8} md={8} lg={8} xl={8}>Add tags to query</Col>
            <Col xs={16} sm={16} md={16} lg={16} xl={16}>
              <Select
                showSearch
                onSearch={handleTagSearch}
                mode="multiple"
                style={{ width: '100%' }}
                label="add tags"
                onChange={addTags}
                value={selectedTags}
              >
                {
                  tags.map(tag => (
                    <Select.Option value={tag.value} key={tag.value}>
                      {tag.value}
                    </Select.Option>
                  ))
                }
              </Select>
            </Col>
          </Row>
        </React.Fragment>
        )}
      </Col>
    </Row>
  );
};

export default React.memo(EventRule);
