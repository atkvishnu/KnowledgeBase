import axios from 'axios';

export const EVENTS_API = '/v1/eventRules';
export const GROUPS_API = '/v1/eventRules/groups';

export const DATA_SOURCES = 'api/data_sources';
export const QUERIES = 'api/queries';
export const ALERTS = 'api/alerts';
export const EVENTS = 'api/events';
export const TAGS = 'api/queries/tags';

export const VISUALIZATION = 'api/visualizations';
export const WIDGETS = 'api/widgets';
export const FIND_FIELDS = '/v1/utils/find_fields';
export const DASHBOARDS = 'api/dashboards';
export const IMPORT_DASHBOARD = '/v1/dashboards/import';

export const GET_TASK = '/v1/tasks';


export const ALERT_DESTINATIONS = 'api/destinations';
export const VALIDATE_RE2 = '/v1/utils/validate/re2';
export const VALIDATE_RULE_NAME = '/v1/eventRules/exists';
export const VALIDATE_RULE_CONDITION = '/v1/eventRules/condition/unique';
export const EVENT_SEQUENCE_GENERATOR = '/v1/eventRules/sequence/next';


export const findFieldTypes = async (message, label) => {
  const payload = {
    message,
  };
  const response = await (await axios.post(FIND_FIELDS, payload)).data;
  if (response.type !== 'UNKNOWN') {
    return { ...response, label };
  }

  return {};
};

export const SANITIZE_REGEX = /\W/gm;
export const LABEL_REGEX = /<(?<label_name>\w+)>/;
export const NUMBER_REGEX = /^([\d.]+\d+)\w*$/gm;
export const ALLOWED_REGEX = /http|status|code|port/;
export const NUMERIC_ONLY_REGEX = /^[0-9]*[.]?[0-9]*$/;

export const sanitizeLabel = (label) => {
  let newLabel = label;
  const labelsRegex = LABEL_REGEX.exec(label);
  if (labelsRegex !== null && 'label_name' in labelsRegex.groups) {
    newLabel = labelsRegex.groups.label_name;
  }
  newLabel = newLabel.replace(SANITIZE_REGEX, '_');

  return newLabel;
};


export const MATCH = 'EVALUATE';
export const REWRITE = 'REWRITE';
export const SIEM = 'SIEM';
export const DROP = 'REGEXDROP';
export const EXTRACT = 'EXTRACT';
export const LOG2METRICS = 'Log2Metrics';
export const FORWARD = 'FORWARD';

export const RULES_TYPE = [
  {
    name: 'FILTER',
    ruleType: DROP,
    order: 1,
    title: 'Filters the messages passing the criterion',
    className: 'logiq-rule-filter',
  },
  {
    name: 'EXTRACT',
    ruleType: EXTRACT,
    order: 2,
    title: 'Exrtacts the messages passing the criterion',
    className: 'logiq-rule-extract',
  },
  {
    name: 'SIEM',
    ruleType: SIEM,
    order: 3,
    title: 'Create event on the messages passing the criterion',
    className: 'logiq-rule-siem',
  },
  {
    name: 'TAG',
    ruleType: MATCH,
    order: 4,
    title: 'Create event on the messages passing the evaluation criterion',
    className: 'logiq-rule-evaluate',
  },
  {
    name: 'REWRITE',
    ruleType: REWRITE,
    order: 5,
    title: 'Mask matched strings',
    className: 'logiq-rule-rewrite',
  },
  {
    name: 'FORWARD',
    ruleType: FORWARD,
    order: 6,
    title: 'FORWARD',
    className: 'logiq-rule-forward',
  },
];

export const RULES_TYPE_NAME = {
  FORWARD: 'FORWARD',
  REWRITE: 'REWRITE',
  EVALUATE: 'TAG',
  SIEM: 'SIEM',
  EXTRACT: 'EXTRACT',
  REGEXDROP: 'FILTER',
};

export const SAVING_RULES = ['REGEXDROP'];


export const NO_NAME_CAPTURE_GROUP = 'There is no name capture group available for the given pattern.';
export const HELP_DROP_LABELS = 'The selected labels will get dropped from the message instead of the entire message.';
export const HELP_FORWARD_LABELS = 'Mark - Only the selected labels and their values will get forwarded instead of the entire message. Message Will contain label1=value1,value2 label2=value3.';
export const HELP_RENAME_LABELS = 'Before forwarding rename the labels.';
export const HELP_CUSTOM_RENAME_LABELS = 'Add custom labels which needs to be renamed, for future use.';
