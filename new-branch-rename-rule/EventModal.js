/* eslint-disable no-use-before-define */
/* eslint-disable no-console */
/* eslint-disable react/prop-types */
/* eslint-disable no-unused-vars */
import {
  Alert,
  Button,
  message,
  Modal,
  PageHeader,
  Steps,
} from 'antd';
import axios from 'axios';
import axiosRetry from 'axios-retry';
import moment from 'moment';
import React from 'react';
import { capitalize } from 'lodash';
import AreaPlot from './AreaPlot';

import './eventModal.less';
import StructuredData from './StructuredData';
import EventRule from './EventRule';
import EventVis from './EventVis';
import EventAlert from './EventAlert';
import RulePreview from './RulePreview';
import RecordMetrics from './RecordMetricsOnly';
import 'antd/lib/steps/style/index.css';
import 'antd/lib/message/style/index.css';
import 'antd/lib/page-header/style/index.css';
import { EVENTS_API,
  DATA_SOURCES,
  QUERIES,
  ALERTS,
  EVENTS,
  VISUALIZATION,
  WIDGETS,
  DASHBOARDS,
  VALIDATE_RULE_CONDITION,
  EVENT_SEQUENCE_GENERATOR, DROP, sanitizeLabel, MATCH, REWRITE, EXTRACT, LOG2METRICS, SIEM, FORWARD } from './constants';
import wait from '../../utils/wait';
import QueryPreview from './QueryPreview';
import QuantilePlot from './QuantilePlot';
import { currentUser } from '../../services/auth';
import { containsMathSymbol } from '../searchAutoComplete/AdvanceSearch';
import Banner from '../alerts/alert-banners/index';


const RETRIES = 5;


axiosRetry(axios, { retries: 5 });


const { Step } = Steps;
export const EVENT_FIELDS = {
  Message: { text: '', operator: '=~', checked: false, writable: true, collapse: true },
  AppName: { text: '', operator: '==', checked: true, writable: true, collapse: true },
  SeverityString: { text: '', operator: '==', checked: false, writable: true, collapse: true },
  Namespace: { text: '', operator: '==', checked: true, writable: true },
  ApplicationMatch: { text: '', operator: '==', checked: false, writable: false },
  FacilityString: { text: '', operator: '==', checked: false, writable: true, collapse: true },
  Hostname: { text: '', operator: '==', checked: false, writable: true },
  Sender: { text: '', operator: '==', checked: false, writable: true, collapse: true },
  Match: { text: '', operator: '==', checked: false, writable: true, collapse: true },
  Rewrite: { text: '', operator: '==', checked: false, writable: true, collapse: true },
  Psid: { text: '', operator: '==', checked: false, writable: true, collapse: true },
};

const EXCLUDE_RULE_TYPES = [REWRITE, DROP, EXTRACT, FORWARD];

const EventModal = ({ log,
  handleCancel,
  visible,
  additionalNamespaces = [],
  labelsMode = 'multiple',
  pageTitle = 'Log2Metric',
  rType,
  clsName,
  footerButtonText,
  extRuleType,
  bundleType,
  additionalProps,
  isCreateRule = false }) => {
  // const [visible, setVisible] = React.useState(true);
  const [untilDate, setUntilDate] = React.useState(null);
  const [current, setCurrent] = React.useState(0);
  const [until, setUntil] = React.useState(false);
  const [eventGroups, setEventGroups] = React.useState([]);
  const [eventDataSources, setEventDataSources] = React.useState([]);

  const [subscriptions, setSubscriptions] = React.useState([]);
  const [dataSource, setDataSource] = React.useState();
  const [operator, setOperator] = React.useState('>=');
  const [active, setActive] = React.useState(0);
  const [preview, setPreview] = React.useState(false);
  const [logiqDS, setLogiqDS] = React.useState(true);

  const [footerText, setFooterText] = React.useState(footerButtonText || 'Next');

  const [loadingFooter, setLoadingFooter] = React.useState(false);
  const [confirmLoading, setConfirmLoading] = React.useState(false);
  const [structuredData, setStructuredData] = React.useState([]);

  const [visDashboards, setVisDashboards] = React.useState(null);
  const [dashboardName, setDashBoardName] = React.useState(null);
  const [metricFlag, setMetricFlag] = React.useState(false);
  const [freqFlag, setFreqFlag] = React.useState(false);
  const [timeField, setTimeField] = React.useState({});
  const [metricField, setMetricField] = React.useState({});
  const [strucuturedDataFields, setStrucuturedDataFields] = React.useState({});
  const [additionalLabels, setAdditionalLabels] = React.useState([]);
  const [selectedRenamedLabels, setSelectedRenamedLabels] = React.useState([]);
  const [customRenamedLabels, setCustomRenamedLabels] = React.useState([]);
  const [patternLabels, setPatternLabels] = React.useState([]);
  const [structureDataCount, setStructureDataCount] = React.useState(0);
  const [tags, setTags] = React.useState([]);
  const [uniqueName, setUniqueName] = React.useState(true);
  const [uniqueCondition, setUniqueCondition] = React.useState(false);
  const [groupByLabel, setGroupByLabel] = React.useState('');
  const [validationError, setValidationError] = React.useState({
    error: false,
    text: '',
  });
  const [eventDescription, setEventDescription] = React.useState({
    name: '',
    level: '',
    description: '',
    groupName: '',
  });
  // Collapse prop will mark them under dropdown for structured data
  const [eventFields, setEventFields] = React.useState(EVENT_FIELDS);

  const [eventFieldsQuery, setEventFieldsQuery] = React.useState({});

  const [condition, setCondition] = React.useState('');

  const [alertFields, setAlertFields] = React.useState({
    options: {

    },
    rearm: 300,
    name: '',
    description: '',
    occurances: 1,
    operator: '==',
    eventPeriod: '5m',
    refresh: 300,
  });

  const [sequence, setSequence] = React.useState('');
  const [ruleType, setRuleType] = React.useState(rType || DROP);
  const [enableDropLabels, setEnableDropLabels] = React.useState(false);
  const [createRule, setCreateRule] = React.useState(false);


  // Setting user group ids as part of prometheous query, to filter the query by user group ids
  const groupIds = '';
  if (currentUser.groups && currentUser.groups.length > 0) {
    const gIds = currentUser.groups.join('_');
    // groupIds = `__g_${gIds}_g__`;
  }
  React.useEffect(() => {
    (async () => {
      const sequenceResponse = await (await axios.get(EVENT_SEQUENCE_GENERATOR)).data;
      if ('sequence' in sequenceResponse) {
        if ('id' in sequenceResponse.sequence) {
          const __sequence = sequenceResponse.sequence.id;
          setSequence(__sequence);
        }
      }
    })();
  }, []);


  React.useEffect(() => {
    setCreateRule(isCreateRule);
  }, [isCreateRule]);


  const getEventsFieldQueryData = (_tmp) => {
    if (_tmp != null && typeof _tmp === 'object' && Object.keys(_tmp).length !== 0) {
      const AND = [];
      Object.keys(_tmp).forEach((key) => {
      // these keys will all go in `and` block
        const OR = [];
        Object.keys(_tmp[key]).forEach((innerKey) => {
          let { currentField } = _tmp[key][innerKey];
          const _searchValue = _tmp[key][innerKey].searchValue;
          const _operator = _tmp[key][innerKey].operator;
          if (_searchValue !== '' && currentField !== '') {
            if (containsMathSymbol(currentField)) {
              currentField = `[${currentField}]`;
            }
            let _query;

            if (isNaN(_searchValue)) {
              const __searchValue = _searchValue.replace(/\\([\s\S])|(")/g, '\\$1$2');
              _query = `${currentField} ${_operator} '${__searchValue}'`;
            } else {
              if (_operator === '=~' || _operator === '!~') {
                _query = `${currentField} ${_operator} '${_searchValue}'`;
              } else {
                _query = `${currentField} ${_operator} ${_searchValue}`;
              }
            }

            OR.push(_query);
          }
        });

        if (OR.length > 0) {
          const combined = `(${OR.join(' || ')})`;
          AND.push(combined);
        }
      });
      if (AND.length > 0) {
        const _combined = `${AND.join(' && ')}`;
        return _combined;
      } return '';
    }
    return _tmp;
  };

  const processEventsFieldQuery = (_eventFieldsQuery) => {
    let _queryValue = '';
    if (_eventFieldsQuery != null && typeof _eventFieldsQuery === 'object' && Object.keys(_eventFieldsQuery).length > 0) {
      _queryValue = getEventsFieldQueryData(_eventFieldsQuery);
    }
    const updatedConditions = Object.keys(eventFields)
      .filter(field => eventFields[field].checked === true && eventFields[field].text !== '')
      .map(field => `(${eventFields[field].text})`);
    if (eventFields.ApplicationMatch.text !== '') {
      updatedConditions.push(`(AppName=~'${eventFields.ApplicationMatch.text}')`);
    }
    const joinedCondition = updatedConditions.join(' && ');
    const _condition = _queryValue !== '' ? (_queryValue + ' && ' + joinedCondition) : joinedCondition;
    setCondition(_condition);
  };

  React.useEffect(() => {
    (async () => {
      try {
        const dataSources = (await (await axios.get(DATA_SOURCES)).data);
        const prometheusTypes = ['logiq_prometheus'];
        const filtered = dataSources.filter(ds => prometheusTypes.includes(ds.type));
        if (filtered.length > 0) {
          setEventDataSources(filtered);
          setDataSource(filtered[0].id);
        } else {
          setLogiqDS(false);
          Banner.show('No logiq prometheus data source configured, Kindly contact admin to configure one.', Banner.ERROR);
          // message.error('No logiq prometheus data source configured, Kindly contact admin to configure one.');
        }
      } catch (error) {
        throw new Error(error);
      }
    })();
  }, []);


  React.useEffect(() => {
    const tempEventFields = { ...eventFields };
    const fields = Object.keys(eventFields);
    Object.keys(log).forEach((key) => {
      if (key in eventFields) {
        //  console.log(key, log[key]);
        if (Array.isArray(log[key])) {
          console.log('an array', key, log[key][0]);
          tempEventFields[key].text = `${key}=='${log[key][0]}'`;
        } else {
          tempEventFields[key].text = `${key}=='${log[key]}'`;
        }
      }
    });
    // This is specific to application match alone, not sure if we need it though?
    // tempEventFields.ApplicationMatch.text = log.AppName;
    // tempEventFields.ApplicationMatch.text = tempEventFields.AppName.text;
    delete tempEventFields.AppName;
    setEventFields(tempEventFields);


    if (typeof (log) === 'object' && 'StructuredData' in log && log.StructuredData.length > 0) {
      setStructureDataCount(log.StructuredData.length);
      const tempStructuredData = {};
      log.StructuredData.forEach((data) => {
        tempStructuredData[data.key] = {
          values: data.values,
          added: false,
          id: Math.random().toString(36).substring(7),
        };
      });
      // setStructuredData(tempStructuredData);
      // Checking for time field in message
      const { Message } = log;
    }

    if (typeof (log) === 'object' && 'fieldsQueryObj' in log) {
      setEventFieldsQuery(log.fieldsQueryObj);
    }
  }, [log]);


  const checkUniquenessofEvent = async (__condition, __additionalLabels) => {
    const ruleObject = {
      condition: __condition,
      additionalLabels: JSON.stringify(__additionalLabels),
    };

    const response = await (await axios.post(VALIDATE_RULE_CONDITION, { rule_object: ruleObject })).data;
    const ErrorMessage = ({ ruleCondition, ruleName }) => (
      <React.Fragment>
        <strong>{ruleCondition}</strong> already exists. Kindly check the rule <strong>{ruleName}</strong>
      </React.Fragment>
    );
    if (response.exists) {
      // Alert for duplicate
      message.error(<ErrorMessage ruleCondition={__condition} ruleName={response.name} />);
      setUniqueCondition(false);
    } else { setUniqueCondition(true); }
  };

  React.useEffect(() => {
    const structuredConditions = [];
    const updatedConditions = Object.keys(eventFields)
      .filter(field => eventFields[field].checked === true && eventFields[field].text !== '')
      .map(field => `(${eventFields[field].text})`);
    if (eventFields.ApplicationMatch.text !== '') {
      updatedConditions.push(`(AppName=~'${eventFields.ApplicationMatch.text}')`);
    }

    const joinedCondition = updatedConditions.join(' && '); // conditions.join(' && ');
    const structuredCondition = []; // structuredConditions.join(' && ');
    const _condition = structuredConditions.length > 0 ? `${joinedCondition} && ${structuredCondition}` : `${joinedCondition}`;
    setCondition(_condition);
    if (typeof (log) === 'object' && 'fieldsQueryObj' in log) {
      processEventsFieldQuery(log.fieldsQueryObj);
    } else {
      processEventsFieldQuery(eventFieldsQuery);
    }
  }, [eventFields]);


  React.useEffect(() => {
    (async () => { await checkUniquenessofEvent(condition, additionalLabels); })();
  }, [condition, additionalLabels]);

  const validateSubmission = () => {
    const validationResponse = {
      valid: true,
      fields: [],
    };

    const { name, level, description, groupName, namespace } = eventDescription;
    const { ApplicationMatch } = eventFields;
    const { rearm,
      occurances,
      eventPeriod,
      refresh } = alertFields;

    if (!(/^\d+$/).test(occurances)) {
      validationResponse.valid = false;
      validationResponse.fields.push('occurances');
    }
    if (!(/^\d+$/).test(refresh)) {
      validationResponse.valid = false;
      validationResponse.fields.push('refresh');
    }
    if (!(/^\d+$/).test(rearm)) {
      validationResponse.valid = false;
      validationResponse.fields.push('rearm');
    }
    if (!(/^\d+[sSmMhHdDwW]/).test(eventPeriod)) {
      validationResponse.valid = false;
      validationResponse.fields.push('eventPeriod');
    }

    let eventSeconds;
    switch (eventPeriod.slice(eventPeriod.length - 1, eventPeriod.length).toLowerCase()) {
      case 'm':
        eventSeconds = parseInt(eventPeriod.slice(0, eventPeriod.length - 1), 10) * 60;
        break;
      case 'h':
        eventSeconds = parseInt(eventPeriod.slice(0, eventPeriod.length - 1), 10) * 60 * 60;
        break;
      case 'd':
        eventSeconds = parseInt(eventPeriod.slice(0, eventPeriod.length - 1), 10) * 60 * 60 * 24;
        break;
      case 'w':
        eventSeconds = parseInt(eventPeriod.slice(0, eventPeriod.length - 1), 10) * 60 * 60 * 24 * 7;
        break;
      case 's':
        eventSeconds = parseInt(eventPeriod.slice(0, eventPeriod.length - 1), 10) * 1;
        break;
      default:
        eventSeconds = parseInt(eventPeriod.slice(0, eventPeriod.length - 1), 10) * 60;
        break;
    }


    if (eventSeconds < 5 * 60 || eventSeconds < occurances) {
      validationResponse.valid = false;
      validationResponse.fields.push('event period');
    }


    if (ApplicationMatch.text === '') {
      validationResponse.valid = false;
      validationResponse.fields.push('applicationMatch');
    }
    if (name.replace(/_/g, '') === '') {
      validationResponse.valid = false;
      validationResponse.fields.push('name');
    }
    if (level === '' && [SIEM, MATCH].includes(ruleType)) {
      validationResponse.valid = false;
      validationResponse.fields.push('level');
    }
    if (description === '') {
      validationResponse.valid = false;
      validationResponse.fields.push('description');
    }
    if (groupName === '') {
      validationResponse.valid = false;
      validationResponse.fields.push('group');
    }

    if (ruleType === FORWARD) {
      if (namespace === '') {
        validationResponse.valid = false;
        validationResponse.fields.push('namespace');
      }
    }

    Object.keys(eventFields).forEach((field) => {
      if (eventFields[field].checked === true) {
        if (eventFields[field].text === '') {
          validationResponse.valid = false;
          validationResponse.fields.push(field);
        }
      }
    });

    // Validating strucutured data fields


    return validationResponse;
  };

  const updateMetricFlag = () => {
    setMetricFlag(!metricFlag);
  };


  const httpQuery = (query, method = 'GET', payload = {}) => {
    // This method will handle all the queries with a retry
  };


  const handleStructureDataFieldSubmit = async (obj, _query, vizType = false, index, queryOptions = {}) => {
    await wait(500);

    try {
      const _name = Object.keys(obj)[0];
      let name = `${alertFields.name}_${_name.replace(/\W+/g, '_')}__e${sequence}e`;
      console.log({ _name, name, obj, _query });
      const _tags = [...tags, name, `e${sequence}e`];
      if (_tags.indexOf('log2metric') < 0) {
        _tags.push('log2metric');
      }

      if (_query.endsWith('quantile=1')) {
        name = `${name}_quantile`;
      }
      if (_query.includes('avg_over_time')) {
        name = `${name}_average`;
      }
      if (_query.includes('rate')) {
        name = `${name}_rate`;
      }
      // let name = `${alertFields.name}_${_name.replace(/\./g, '_')}_${Math.random().toString(36).substring(7)}`;
      if (vizType) {
        name = `${name}-Vis`;
        queryOptions.subType = 'vis';
      }
      const queryData = {
        schedule: {
          interval: parseInt(alertFields.refresh, 10),
          until: untilDate,
          time: null,
          day_of_week: null,
        },
        query: _query,
        description: alertFields.description,
        name,
        data_source_id: dataSource,
        version: parseInt(index, 10) + 1,
        tags: _tags,
        is_draft: true,
        options: { log2metricData: queryOptions },
      };


      let id;
      const url = `${QUERIES}?q=${Math.random().toString(36).substring(2)}`;
      const query = await (await axios.post(url, queryData)).data;
      id = query.id;
      const draftToActive = {
        name,
        is_draft: false,

      };

      if (id === null || id === undefined) {
        const __query = await (await axios.post(url, queryData)).data;
        console.log('response query 2: ', __query);
        id = __query.id;
      }
      setFooterText('Setting query as active');
      if (id !== '' && id !== undefined && id !== null) {
        const QUERY_ACTIVE_URL = `${QUERIES}/${id}`;
        const activeResponse = await (await axios.post(QUERY_ACTIVE_URL, draftToActive)).data;
        // Executing query
        const executionResultURL = `${QUERY_ACTIVE_URL}/results`;

        const resultPayload = {
          id,
          max_age: 0,
          parameters: {},
        };
        setFooterText('Executing query');
        await (await axios.post(executionResultURL, resultPayload)).data;


        if (!activeResponse.is_draft) {
          // Executing the query atleast once
          const executionPayload = [
            {
              action: 'execute',
              object_type: 'query',
              object_id: id,

            },
          ];

          await (await axios.post(EVENTS, executionPayload)).data;
        }


        if (obj[_name].alert && vizType === false) {
        // creating an alert
          const _operator = obj[_name].operator;
          const alertPayload = {
            options: {
              column: 'value',
              op: _operator,
              value: parseInt(obj[_name].occurrences, 10),
            },
            rearm: parseInt(alertFields.rearm, 10),
            name: `${name}: value ${_operator} ${obj[_name].occurrences}`,
            query_id: id,
          };

          const alertResponse = await (await axios.post(ALERTS, alertPayload)).data;


          if (subscriptions.length > 0) {
          // Adding subscriptions
            const subscriptionPayload = {
              alert_id: alertResponse.id,
              destination_id: subscriptions[0],
            };

            const subscriptionURL = `${ALERTS}/${alertResponse.id}/subscriptions`;
            const destinationResponse = await (await axios.post(subscriptionURL, subscriptionPayload)).data;
          }
        // Marking the alert on rule active
        // payload.alertConfigured = alertResponse.id;
        // console.log('Marking it active');
        // setFooterText('Activating queries');
        // await (await axios.put(`${EVENTS_API}/${eventDescription.name}`, payload)).data;
        }


        if (vizType) {
          let visPayload;
          if (_query.endsWith('quantile=1')) {
            visPayload = { ...QuantilePlot };
          } else {
            visPayload = { ...AreaPlot };
          }

          visPayload.name = `${name}-Vis`;
          visPayload.query_id = id;
          setFooterText('Creating visualization');
          const visResult = await (await axios.post(VISUALIZATION, visPayload)).data;


          if (visDashboards !== null) {
          // adding to dashboard
            const widgetPayload = {
              options: {
                position: {
                  autoHeight: false,
                  maxSizeX: 6,
                  maxSizeY: 1000,
                  minSizeX: 1,
                  minSizeY: 5,
                  row: 8,
                  sizeX: 3,
                  sizeY: 8,
                },
              },
              width: 1,
              dashboard_id: visDashboards,
              visualization_id: visResult.id,
            };

            await (await axios.post(WIDGETS, widgetPayload)).data;
            await (await axios.get(DATA_SOURCES)).data;
          }
        }
      }
    } catch (error) {
      console.error(error.response.data);
      // message.error(`Error while creating Event.: ${error.response.data.error}`);
      Banner.show(`Error while creating Event/Rule.: ${error.response.data.error}`, Banner.ERROR);
      setFooterText(!createRule ? 'Create event' : 'Create rule');
      setLoadingFooter(false);
    }
  };

  const generateLabelsObj = () => {
    const _newObj = [additionalLabels, selectedRenamedLabels, customRenamedLabels];
    const [labels, renamedLabels, customLabels] = _newObj;
    const newObj = { labels, renamedLabels, customLabels };
    // console.log('DATA object------------->', newObj);
    if (Array.isArray(newObj.renamedLabels)) {
      newObj.renamedLabels = {};
    }
    if (Array.isArray(newObj.customLabels)) {
      newObj.customLabels = {};
    }
    Object.keys(newObj.renamedLabels).forEach((key) => {
      if (newObj.renamedLabels[key] === '' || newObj.renamedLabels[key] === ' ') {
        delete newObj.renamedLabels[key];
      }
    });
    Object.keys(newObj.customLabels).forEach((key) => {
      if (newObj.customLabels[key] === '' || newObj.customLabels[key] === ' ') {
        delete newObj.customLabels[key];
      }
    });
    // console.log('DATA object after update------------->', newObj);
    return newObj;
  };

  const handleSubmit = async (e) => {
    // setLoadingFooter(true);

    const retObj = generateLabelsObj();

    // setFooterText('Validating fields data');
    const validationResponse = validateSubmission();
    if (!validationResponse.valid) {
      setValidationError({
        error: true,
        text: `Oops! Following fields must not be empty or invalid: ${JSON.stringify(validationResponse.fields)}`,
      });

      // setFooterText('Validation failed');
      return;
    }


    const eventMetrics = [];
    const doneEvents = {};

    Object.keys(strucuturedDataFields).forEach((k) => {
      const _tmp = {};
      _tmp.name = `${eventDescription.name}${groupIds}__e${sequence}e`;
      const sKey = Object.keys(strucuturedDataFields[k])[0];
      const { type, label, plotType } = strucuturedDataFields[k][sKey];
      _tmp.type = type === 'FLOAT' ? 1 : 3; // 1 for gauge, 3 for histogram, 2 is for Counter for future ref
      _tmp.targetField = label;
      _tmp.fieldType = type.toLowerCase();
      _tmp.plotType = plotType;
      const uniqueKey = `${_tmp.name}_${_tmp.type}_${_tmp.plotType}_${label.replace(/\W+/gm, '_')}`;

      if ('regex' in strucuturedDataFields[k][sKey] && 'patternLabel' in strucuturedDataFields[k][sKey]) {
        const { regex, patternLabel } = strucuturedDataFields[k][sKey];
        _tmp.regex = regex;
        _tmp.patternLabel = patternLabel;
      }
      if ('uniqueHash' in strucuturedDataFields[k][sKey]) {
        _tmp.uniqueHash = strucuturedDataFields[k][sKey].uniqueHash;
      }
      if (!(uniqueKey in doneEvents)) {
        doneEvents[uniqueKey] = 1;
        eventMetrics.push(_tmp);
      }

      console.log({ eventMetrics, doneEvents });
    });
    let nameSpace = eventDescription.namespace || '';
    if (nameSpace === '') {
      nameSpace = eventFields.Namespace.text ? eventFields.Namespace.text.replace(/'/g, '') : '';
      nameSpace = nameSpace && nameSpace.split('==');
      if (nameSpace.length > 0) {
        nameSpace = nameSpace[1];
      }
    }


    // const eventMetrics = [strucuturedDataFields[Object.keys(strucuturedDataFields)[0]]];
    const payload = {
      groupName: eventDescription.groupName,
      name: `${eventDescription.name}__e${sequence}e`,
      level: eventDescription.level,
      description: eventDescription.description,
      namespace: nameSpace || '',
      applicationMatch: eventFields.ApplicationMatch.text,
      active: 1,
      ruleType,
      recordMetricsOnly: metricFlag === true ? 0 : 1,
      immutable: 0,
      tags,
      recordTimeField: freqFlag === true ? 1 : 0,
      eventMetrics,
      // additionalLabels: additionalLabels.filter(label => label !== '' && !label.includes('(?P<')),
      additionalLabels: retObj,
      patternLabels: patternLabels.filter(label => additionalLabels.includes(label.pattern)),
    };

    // extRuleType will be SIEM while creating the new from rule packs, else it will be undefined.
    // if (extRuleType && ruleType === MATCH) {
    //   payload.extRuleType = extRuleType;
    // }

    if (ruleType === REWRITE) {
      payload.match = eventFields.Match.text;
      payload.rewrite = eventFields.Rewrite.text;
    }

    payload.condition = condition;

    setFooterText(!createRule ? 'Create event' : 'Create rule');
    setLoadingFooter(true);

    try {
      const response = await (await axios.post(EVENTS_API, payload)).data;
      const __alertFieldName = `${alertFields.name}`;

      const _tags = [...tags, `e${sequence}e`];
      if (_tags.indexOf('log2metric') < 0) {
        _tags.push('log2metric');
      }
      // if (ruleType !== 'REWRITE') {
      if (!EXCLUDE_RULE_TYPES.includes(ruleType)) {
        let promQL = `sum(increase(logiq_ae_${__alertFieldName}_count[${alertFields.eventPeriod}]) OR on() vector(0))`;
        if (additionalLabels.length > 0) {
          const __additionalLabels = additionalLabels.map(label => sanitizeLabel(label));
          promQL = `sum by (${__additionalLabels.join(', ')}) (increase(logiq_ae_${__alertFieldName}_count[${alertFields.eventPeriod}]))`;
        }

        const queryData = {
          schedule: {
            interval: parseInt(alertFields.refresh, 10),
            until: untilDate,
            time: null,
            day_of_week: null,
          },
          query: promQL,
          description: alertFields.description,
          name: `${__alertFieldName}`,
          data_source_id: dataSource,
          version: 2,
          tags: _tags,
          is_draft: true,
        };

        const promQLVisQuery = `${promQL}&duration=1h&step=5m`;
        // eslint-disable-next-line max-len
        // `sum(rate(logiq_ae_${__alertFieldName}_count[${alertFields.eventPeriod}]) OR on() vector(0))&duration=1h&step=5m`,
        const queryDataVis = {
          schedule: {
            interval: parseInt(alertFields.refresh, 10),
            until: untilDate,
            time: null,
            day_of_week: null,
          },
          query: promQLVisQuery,
          description: alertFields.description,
          name: `${__alertFieldName}_rate_Vis`,
          data_source_id: dataSource,
          version: 1,
          tags: _tags,
          is_draft: true,
        };

        const queryOptions = {};
        // if (visDashboards !== null) {
        let _nameSpace = eventFields.Namespace.text ? eventFields.Namespace.text.replace(/'/g, '') : '';
        _nameSpace = _nameSpace && _nameSpace.split('==');
        if (_nameSpace.length > 0) {
          queryOptions.namespace = _nameSpace[1];
          queryOptions.application = eventFields.ApplicationMatch.text;
          queryOptions.name = `${eventDescription.name}${groupIds}__e${sequence}e`;
          queryOptions.type = 'log2metric';
          queryOptions.additionalLabels = additionalLabels;
          queryData.options = { log2metricData: queryOptions };
          queryDataVis.options = { log2metricData: queryOptions };
        }
        // }


        // setFooterText('Creating vis query');
        const query = await (await axios.post(`${QUERIES}?q=${Math.random().toString(36).substring(2)}`, queryData)).data;

        let id = query.id;
        // temp hack
        // TODO: FIXME
        if (id === null || id === undefined) {
          const __query = await (await axios.post(`${QUERIES}?q=${Math.random().toString(36).substring(2)}`, queryData)).data;
          console.log('response query 2: ', __query);
          id = __query.id;
        }

        const queryVis = await (await axios.post(`${QUERIES}?q=${Math.random().toString(36).substring(2)}`, queryDataVis)).data;

        let visID = queryVis.id;
        if (visID === null || visID === undefined) {
          const __queryVis = await (await axios.post(`${QUERIES}?q=${Math.random().toString(36).substring(2)}`, queryDataVis)).data;
          console.log('response vis 2: ', __queryVis);
          visID = __queryVis.id;
        }


        const draftToActive = {
          name: `${__alertFieldName}`,
          is_draft: false,

        };
        // setFooterText('Setting query as active');

        const draftToActiveVIS = {
          name: `${__alertFieldName}-Vis`,
          is_draft: false,

        };

        // setFooterText('Setting vis query as active');


        const QUERY_ACTIVE_URL = `${QUERIES}/${id}`;
        const activeResponse = await (await axios.post(QUERY_ACTIVE_URL, draftToActive)).data;

        const QUERY_ACTIVE_URL_VIS = `${QUERIES}/${visID}`;
        const activeResponseVIS = await (await axios.post(QUERY_ACTIVE_URL_VIS, draftToActiveVIS)).data;


        // Executing query
        const executionResultURL = `${QUERY_ACTIVE_URL}/results`;

        const resultPayload = {
          id,
          max_age: 0,
          parameters: {},
        };

        const resultPayloadVis = {
          id: visID,
          max_age: 0,
          parameters: {},
        };

        // setFooterText('Executing query');
        await (await axios.post(executionResultURL, resultPayload)).data;

        // setFooterText('Executing vis query');

        await (await axios.post(executionResultURL, resultPayloadVis)).data;


        if (!activeResponse.is_draft) {
          // Executing the query atleast once
          const executionPayload = [
            {
              action: 'execute',
              object_type: 'query',
              object_id: id,

            },
          ];
          const executionPayloadVis = [
            {
              action: 'execute',
              object_type: 'query',
              object_id: visID,

            },
          ];
          await (await axios.post(EVENTS, executionPayload)).data;
          await (await axios.post(EVENTS, executionPayloadVis)).data;

          if (active === 1) {
            // creating an alert
            const alertPayload = {
              options: {
                column: 'value',
                op: operator,
                value: parseInt(alertFields.occurances, 10),
                alertType: 'simple alert',
              },
              rearm: parseInt(alertFields.rearm, 10),
              name: `${__alertFieldName}: value ${operator} ${alertFields.occurances}`,
              query_id: id,
            };

            const alertResponse = await (await axios.post(ALERTS, alertPayload)).data;


            if (subscriptions.length > 0) {
              // Adding subscriptions
              const subscriptionPayload = {
                alert_id: alertResponse.id,
                destination_id: subscriptions[0],
              };

              const subscriptionURL = `${ALERTS}/${alertResponse.id}/subscriptions`;
              const destinationResponse = await (await axios.post(subscriptionURL, subscriptionPayload)).data;
            }
            // Marking the alert on rule active
            payload.alertConfigured = alertResponse.id;
            // console.log('Marking it active');
            // setFooterText('Activating queries');
            const modifiedEventName = `${eventDescription.name}${groupIds}__e${sequence}e`;
            await (await axios.put(`${EVENTS_API}/${modifiedEventName}`, payload)).data;
          }


          // Creating visualization
          const visPayload = { ...AreaPlot };
          visPayload.name = `${__alertFieldName}-Vis`;
          visPayload.query_id = visID;
          if (groupByLabel !== '') {
            visPayload.options.columnMapping[sanitizeLabel(groupByLabel)] = 'series';
          }
          setFooterText('Creating visualization');
          const visResult = await (await axios.post(VISUALIZATION, visPayload)).data;


          if (visDashboards !== null) {
            // adding to dashboard
            const widgetPayload = {
              options: {
                position: {
                  autoHeight: false,
                  maxSizeX: 6,
                  maxSizeY: 1000,
                  minSizeX: 1,
                  minSizeY: 5,
                  row: 8,
                  sizeX: 3,
                  sizeY: 8,
                },
              },
              width: 1,
              dashboard_id: visDashboards,
              visualization_id: visResult.id,
            };

            await (await axios.post(WIDGETS, widgetPayload)).data;
            await (await axios.get(DATA_SOURCES)).data;

            // Adding the tag to dashboard as well,

            await (await axios.post(`${DASHBOARDS}/${visDashboards}`, {
              tags: [`${__alertFieldName}`],
            })).data;
          }

          // Creating other dashboards here
          const doneQueries = {};
          Object.keys(strucuturedDataFields).forEach((_k) => {
            const _n = Object.keys(strucuturedDataFields[_k])[0];
            const _q = strucuturedDataFields[_k][_n];
            const _tmpQueryName = `${eventDescription.name}${groupIds}__e${sequence}e`;
            const uniqueKey = `${_tmpQueryName}_${_q.type}_${_q.plotType}_${_q.label.replace(/\W+/gm, '_')}`;

            if (!(uniqueKey in doneQueries)) {
              doneQueries[uniqueKey] = 1;
              Promise.all(strucuturedDataFields[_k][_n].queries.map((_query, index) => handleStructureDataFieldSubmit(
                strucuturedDataFields[_k], _query, false, index, queryOptions,
              )))
                .then(resp => console.log('all queries created'))
                .catch(err => console.log(`error while creating queries: ${err}`));


              Promise.all(strucuturedDataFields[_k][_n]
                .viz_queries.map((_query, index) => handleStructureDataFieldSubmit(
                  strucuturedDataFields[_k], _query, true, index, queryOptions,
                )))
                .then(resp => console.log('all vis queries created'))
                .catch(err => console.log(`error while creating vis queries: ${err}`));
            }
          });
          // message.success('Successfully created the event.'e);
          Banner.show(`Successfully created the ${createRule ? 'rule' : 'event'}.`, Banner.SUCCESS);
          handleCancel(); // To close the modal after creating event and alert
        }
      } else {
        // message.success('Successfully created the event.');
        handleCancel();
        Banner.show(`Successfully created the ${createRule ? 'rule' : 'event'}.`, Banner.SUCCESS);
      }
    } catch (error) {
      console.error(error.response.data);
      // message.error(`Error while creating an alertable event.: ${error.response.data.error}`);
      Banner.show(`Error while creating an alertable event.: ${error.response.data.error}`, Banner.ERROR);

      setFooterText('Create Event');
      setLoadingFooter(false);
    }
  };

  const handleAlert = (event) => {
    const tempAlert = { ...alertFields };
    const { name, value } = event.target;
    tempAlert[name] = `${value.replace(/\W+/g, '_')}${groupIds}__e${sequence}e`;

    if (tempAlert.name.replace(/_/g, '') !== '') {
      setPreview(true);
    } else {
      setPreview(false);
    }
    setAlertFields(tempAlert);
  };

  const handleEventMetric = (value) => {
    setMetricField(value);
  };

  const updateFreqFlag = value => setFreqFlag(value);


  const handleStructureData = (value) => {
    console.log({ value });


    setStrucuturedDataFields(value);
  };

  // Merge record event and visualization, 2nd -> metric configuration & visualization
  // Title => log2metric (change everywhere)
  const handleQueries = (keyId, queries) => {
    // do something

    const _tmp = { ...strucuturedDataFields };
    console.log({ _tmp });
    if (keyId in _tmp) {
      const key = Object.keys(_tmp[keyId])[0];

      _tmp[keyId][key].queries = queries;
      setStrucuturedDataFields(_tmp);
    }
  };

  const handleVizQueries = (keyId, queries) => {
    // do something

    const _tmp = { ...strucuturedDataFields };
    if (keyId in _tmp) {
      const key = Object.keys(_tmp[keyId])[0];

      _tmp[keyId][key].viz_queries = queries;
      setStrucuturedDataFields(_tmp);
    }
  };


  const handleEventFieldsQuery = (fieldsQuery) => {
    setEventFieldsQuery(fieldsQuery);
    processEventsFieldQuery(fieldsQuery);
  };

  const handleRuleTypeChange = (value) => {
    setRuleType(value);
    // Clearing the addtitional labels and pattern labels on rule type change.
    // These were holding the previous rule changes.
    setPatternLabels([]);
    setAdditionalLabels([]);
    if (value === MATCH || value === SIEM) {
      setFooterText('Next');
    } else {
      setFooterText('Create rule');
    }
  };

  const handleEnableDropLabelsChange = (enable) => {
    setEnableDropLabels(enable);
  };

  const steps = [
    {
      title: 'Rule Matching',
      content: <EventRule
        key="event_modal_event"
        log={log}
        handleAlert={handleAlert}
        eventDescription={eventDescription}
        setEventDescription={setEventDescription}
        eventFields={eventFields}
        setEventFields={setEventFields}
        condition={condition}
        handleAdditionalLabels={setAdditionalLabels}
        handleRenamedLabels={setSelectedRenamedLabels}
        handleCustomRenamedLabels={setCustomRenamedLabels}
        handleTags={setTags}
        uniqueName={uniqueName}
        setUniqueName={setUniqueName}
        handleEventFieldsQuery={handleEventFieldsQuery}
        fieldsQuery={eventFieldsQuery}
        additionalNamespaces={additionalNamespaces}
        setGroupByLabel={setGroupByLabel}
        setPatternLabels={setPatternLabels}
        patternLabels={patternLabels}
        labelsMode={labelsMode}
        handleRuleType={handleRuleTypeChange}
        rType={ruleType}
        handleEnableDropLabelsChange={handleEnableDropLabelsChange}
        bundleType={bundleType}
        additionalProps={additionalProps}
      />,
    },
    // {

    //   title: 'Record Events',
    //   content: <RecordMetrics
    //     metricFlag={metricFlag}
    //     updateMetricFlag={updateMetricFlag}
    //     structuredData={log.StructuredData}
    //     handleEventMetric={handleEventMetric}
    //     handleStructureData={handleStructureData}
    //   />,
    // },


    {
      title: 'Visualization & Dashboard',
      content: <EventVis
        name={`${eventDescription.name}${groupIds}__e${sequence}e`}
        setVisDashboards={setVisDashboards}
        key="event_modal_vis"
        structuredData={log.StructuredData}
        handleEventMetric={handleEventMetric}
        handleStructureData={handleStructureData}
        handleQueries={handleQueries}
        handleVizQueries={handleVizQueries}
        additionalLabels={additionalLabels}
        setDashBoardName={setDashBoardName}
        message={log.Message}
      />,
    },
    {
      title: 'Alert Configuration',
      content: <EventAlert
        key="event_modal_alert"
        alertName={eventDescription.name}
        operator={operator}
        setOperator={setOperator}
        active={active}
        setActive={setActive}
        subscriptions={subscriptions}
        setSubscriptions={setSubscriptions}
        alertFields={alertFields}
        setAlertFields={setAlertFields}
        until={until}
        setUntil={setUntil}
        untilDate={untilDate}
        logiqDS={logiqDS}
        dataSource={dataSource}
        eventDataSources={eventDataSources}
        setLogiqDS={setLogiqDS}
        setUntilDate={setUntilDate}
        strucuturedDataFields={strucuturedDataFields}
        handleStructureData={handleStructureData}
      />,
    },
  ];


  const next = () => {
    const _current = current + 1;
    setCurrent(_current);
    if (_current === steps.length - 1) {
      setFooterText(!createRule ? 'Create metric' : 'Create rule');
    } else {
      setFooterText('Next');
    }
  };

  const prev = () => {
    const _current = current - 1;
    setCurrent(_current);
    if (_current === steps.length - 1) {
      setFooterText('Create alertable event');
    } else {
      setFooterText('Next');
    }
  };


  const eventDescriptionFieldsPresent = () => {
    const empty = Object.keys(eventDescription).filter((field) => {
      if ([FORWARD, REWRITE, DROP, EXTRACT].includes(ruleType) && field === 'level') {
        return false;
      }
      return eventDescription[field] === '';
    });
    return empty.length === 0;
  };


  const disabledNext = () => {
    if (!logiqDS) {
      return true;
    }
    if (!eventDescriptionFieldsPresent()) {
      return true;
    }

    if (!uniqueName) {
      return true;
    }


    if (!uniqueCondition) {
      return true;
    }

    if (ruleType === DROP && enableDropLabels && additionalLabels.length === 0) {
      return true;
    }

    return false;
  };

  const Title = () => (
    <React.Fragment>
      <PageHeader
        title={!createRule ? 'Create Event' : 'Create Rule'}
        subTitle={`${eventDescription.name}`}
      />
    </React.Fragment>
  );

  return (
    <div>
      <Modal
        className={clsName || ''}
        width="100%"
        destroyOnClose
        maskClosable={false}
        centered
        // heigth
        title={Title()}
        visible={visible}
        onCancel={handleCancel}
        confirmLoading={confirmLoading}
        footer={(ruleType === MATCH || ruleType === SIEM) ? [
          <Button key="back" onClick={prev} disabled={current < 1}>
            Previous
          </Button>,
          <Button key="submit" type="primary" loading={loadingFooter} onClick={current === steps.length - 1 ? handleSubmit : next} disabled={disabledNext()}>
            {footerText}
          </Button>,
        ] : [
          <Button key="submit" type="primary" loading={loadingFooter} onClick={handleSubmit} disabled={disabledNext()}>
            {footerText}
          </Button>,
        ]}
      >
        {validationError.error ? (
          <div>
            <Alert message={validationError.text} type="error" showIcon />
            <br />
          </div>
        ) : null}

        <div
          className="lq-event-modal"
          style={{
            maxHeight: '80vH',
            minHeight: '80vH',
            overflow: 'hidden',
            overflowY: 'scroll',
          }}
        >


          <Steps
            size="small"
            current={current}
            style={{
              paddingRight: '1%',

            }}
          >
            {(ruleType === MATCH || ruleType === SIEM) ?
              steps.map(item => (
                <Step key={item.title} title={item.title} />
              ))
              : <Step className="lq-hidden" key={steps[0].title} title={steps[0].title} /> }

          </Steps>

          <div
            className="steps-content"
            style={{
              paddingRight: '2em',
            }}
          >{steps[current].content}
          </div>


          {
            condition !== '' && current === 0 && (
              <QueryPreview
                condition={condition}
              />
            )
          }
          {
            alertFields.name !== '' && current === 0 && ruleType !== DROP && ruleType !== EXTRACT ? (

              <RulePreview
                name={alertFields.name}
                eventPeriod={alertFields.eventPeriod}
                operator={operator}
                occurances={alertFields.occurances}
                rearm={alertFields.rearm}
                refresh={alertFields.refresh}
                until={until}
                untilDate={untilDate}
                additionalLabels={additionalLabels}
              />

            ) : null
          }

        </div>
      </Modal>
    </div>
  );
};


export default React.memo(EventModal);
