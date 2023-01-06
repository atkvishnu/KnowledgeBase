/* eslint-disable react/sort-comp */
/* eslint-disable no-unused-vars */
/* eslint-disable react/no-unused-state */
/* eslint-disable func-names */
import { LEVELS, LEVEL_LABEL_COLORS } from '@/config/rules-events-constants';
import Filter from '@/pages/events/filter';
import axios from 'axios';
import { toastr } from '@/services/ng';
import { Tag,
  message,
  Button,
  Tooltip,
  Table,
  Row,
  Col,
  Checkbox,
  Icon,
  Dropdown,
  Pagination,
  Menu } from 'antd';
import 'antd/lib/message/style/index.css';
import 'antd/lib/table/style/index.css';
import React from 'react';
import moment from 'moment';
import Syntax from '../../../../components/syntaxHighlight';
import AlertOnEvent from '../../../../components/event-modal/alert';
import '../../../../config/rules-events.less';
import '../../../rules/rules.less';
import { RULES_CRUD_API, RULES_QUERY_API, RULES_ALERT_API, NAMESPACE_API, TAG_REGEX, QUERY_API, EMPTY_LOG } from '../../../rules/rules_constants';
import { DASHBOARDS, MATCH } from '../../../../components/event-modal/constants';
import LogiqTags from '../../../../components/logiqTags';
import EditRuleModal from '../../../rules/EditRuleModal';
import { levelColors } from '../../../../components/ingest/colors';


const { Column } = Table;


const sanitize = (item) => {
  item.active = item.active ? 1 : 0;
  item.immutable = 0; // setting it explicitly but server should always ignore this;
  // item.recordMetricsOnly = item.recordMetricsOnly ? 0 : 1;
  item.alertConfigured = item.alertConfigured > 0 ? 1 : 0;

  if ('additionalLabels' in item && (item.additionalLabels !== null)
      && typeof (item.additionalLabels.labels) === 'string') {
    item.additionalLabels.labels = item.additionalLabels.labels.split(',').map(ele => ele.trim());
  }
  return item;
};

const disableAlert = function (alert) {
  const url = `${RULES_ALERT_API}/${alert}`;
  return fetch(url, {
    method: 'delete',
  })
    .then(resp => resp.json());
};


const removeQueries = async (name) => {
  // Checking if tag exists on query string
  const tags = name.match(TAG_REGEX);
  if (tags.length > 0) {
    const queryAPI = `${QUERY_API}?page=1&q=${name}&tags=${tags[0]}`;
    const response = await (await axios.get(queryAPI)).data;
    if (response.count > 0) {
      response.results.forEach(async (result) => {
        try {
          await (await axios.delete(`${QUERY_API}/${result.id}`)).data;
          message.success(`Removed query ${result.id} associated with event`);
        } catch (err) {
          message.error(`Error while deleting query id ${result.id}, ${err}`);
        }
      });
    }
  }
};

const insert = function (item) {
  item = sanitize(item);
  return fetch(RULES_CRUD_API, {
    method: 'POST',
    body: JSON.stringify(item),
    headers: {
      'Content-Type': 'application/json',
    },
  }).then(resp => resp.json());
};

const update = function (item, values) {
  const alertID = item.alertConfigured;
  item = sanitize({ ...item, ...values });
  return fetch(`${RULES_CRUD_API}/${item.name}`, {
    method: 'PUT',
    body: JSON.stringify(item),
    headers: {
      'Content-Type': 'application/json',
    },
  }).then((resp) => {
    resp.json();
    if ('alertConfigured' in values && values.alertConfigured === false) {
      disableAlert(alertID);
    }
  });
};


const openAlertLink = (activeAlert) => {
  window.open(`/alerts/${activeAlert}`, '_blank');
};


class PackRulesList extends React.Component {
  constructor(props) {
    super(props);

    const _filter = {
      groupNames: [this.props.groupType],
      ruleType: this.props.ruleType,
    };

    this.state = {
      autoRefreshId: this.props.key || null,
      filter: {
        offset: 0,
        count: 15,
        sort: { attribute: 'createdAt', order: 'DESC' },
        filter: { ..._filter },
      },
      showEventModal: false,
      name: '',
      showAlertOnEvent: false,
      showEditRuleModal: false,
      currentRecord: {},
      rules: [],
      tableLoading: true,
      totalCount: 0,

    };
  }


  componentDidMount = () => {
    // handle getting all namespaces from here
    this.refreshContent();
    // const id = setInterval(this.refreshContent, 60000);
    // this.setState({ autoRefreshId: id });
  }


  componentWillUnmount() {
    // clearInterval(this.state.autoRefreshId);
  }

  refreshContent = () => {
    this.fetchRules();
  }


  fetchRules = async () => {
    let _fetchRules = true;
    try {
      this.setState({ tableLoading: true });
      const response = await (await axios.post(RULES_QUERY_API, this.state.filter)).data;
      if ('eventRules' in response) {
        const eventRules = response.eventRules;
        const totalRules = parseInt(response.total_count, 10);
        eventRules.forEach((rule) => { rule.key = `${rule.name}`; });
        if (_fetchRules) {
          this.setState({ rules: eventRules, totalCount: totalRules, tableLoading: false });
        }
      }
    } catch (err) {
      console.error(err);
      message.error('error fetching rules');
    }

    return () => { _fetchRules = false; };
  };

  handleRuleEdit = (record) => {
    this.setState({ showEditRuleModal: true, currentRecord: record });
  }

  remove = item => fetch(`${RULES_CRUD_API}/${item.name}`, {
    method: 'DELETE',
  }).then((resp) => {
    resp.json();
    removeQueries(item.name);
    if (item.alertConfigured > 0) {
      const alert = item.alertConfigured;
      disableAlert(alert);
    }
    this.refreshContent();
    message.info('Successfully deleted the rule');
  });

   ruleMoreMenu = ({ record }) => (
     <Menu style={{
       border: '1px solid #f7f5f5',
     }}
     >
       <Menu.Item
         onClick={() => this.handleRuleEdit(record)}
       >
         Edit rule
       </Menu.Item>
       <Menu.Item
         onClick={() => this.dashboardPage(record.name)}
       >
         Go to dashboard
       </Menu.Item>
       <Menu.Item
         onClick={() => this.queriesPage(record.name)}
       >
         Check related queries
       </Menu.Item>
       <Menu.Item
         onClick={() => this.createAlert(record)}
       >
         Create Alert
       </Menu.Item>
       <Menu.Item
         onClick={() => this.remove(record)}
       >
         Delete rule
       </Menu.Item>


     </Menu>
   );


  createAlert = (data) => {
    const alertConfigured = data.alertConfigured;
    if (alertConfigured > 0) {
      window.open(`/alerts/${alertConfigured}`, '_blank');
    } else {
      this.setState({
        // showEventModal: true,
        showAlertOnEvent: true,
        name: data.name,
        alertData: data,
      });
    }
  }

  queriesPage = (name) => {
    let tagName;
    const splitted = name.split('__');
    if (splitted.length > 1) {
      tagName = splitted[1];
    }

    if (tagName !== null || tagName !== undefined) {
      window.open(`/queries?page=1&page_size=20&q=${tagName}`, '_blank');
    } else {
      message.warning(`Only queries created using log2metric utility can be opened from here.
      You can also edit this behaviour by adding a tag with value ${tagName} in the /queries page.
      `);
    }
  }


  dashboardPage = async (name) => {
    const tagName = name;
    if (tagName !== null || tagName !== undefined) {
      const dResponse = await (await axios.get(`${DASHBOARDS}?tags=${tagName}`)).data;
      const { results } = dResponse;
      // Get the first result;
      if (results && results.length > 0) {
        const dName = results[0].slug;
        window.open(`/dashboard/${dName}`, '_blank');
      } else {
        message.warning(`Only dashboard created using log2metric utility can be opened from here.
        You can also edit this behaviour by adding a tag with value ${tagName} in the /dashboard page.
        `);
      }
    }
  }

  handleEventModalCancel = () => {
    this.setState({
      showEventModal: false,
      showAlertOnEvent: false,
    });
    if (this.props.closeCreateNewRuleModal) {
      this.props.closeCreateNewRuleModal();
    }
  }

  handleEditRuleModalCancel = () => {
    this.setState({
      showEditRuleModal: false,
    });
  }

  handleNewEvent = () => {
    this.setState({ showEventModal: true });
  }

  handleEventModalCancel = () => {
    this.setState({ showEventModal: false });
    this.refreshContent();
  }

  handleAlertModalCancel = () => {
    this.setState({ showAlertOnEvent: false });
  }


  formatAdditionalLabels = ({ data }) => {
    const patternLabels = {};
    data.patternLabels.forEach((pattern) => {
      // patternLabels.add(pattern.pattern);
      patternLabels[pattern.pattern] = 1;
    });
    return (
      <React.Fragment>
        <div>
          {
           data.additionalLabels.labels.map(label => (
             <Tag color="cyan" key={label}>
               <Tooltip title={`GROUP BY: ${label}`}>
                 {
                  label.length > 250 ? (`${label.slice(0, 200)}...`) : (`${label}`)
                 }
               </Tooltip>
             </Tag>
           ))
         }
        </div>
        <div>
          {
           Object.keys(patternLabels).map(pattern => (
             <Tag color="red">
               <Tooltip title={`REGEX GROUP BY: ${pattern}`}>
                 {
                 pattern.length > 250 ? (`${pattern.slice(0, 200)}...`) : (`${pattern}`)
               }
               </Tooltip>

             </Tag>
           ))
         }
        </div>
        <div
          className="lgq-grpby-pattern"
        >
          {
            data.eventMetrics.map((metric) => {
              const { targetField, plotType } = metric;
              if (plotType === 'gauge') {
                return (
                  <Tag color="purple">
                    <Tooltip title={`AVG OCCURANCES METRIC: ${targetField}`}>
                      {
                        targetField.length > 250 ? (`${targetField.slice(0, 200)}`) : (`${targetField}`)
                      }
                    </Tooltip>
                  </Tag>
                );
              }
              return (
                <Tag color="orange">
                  <Tooltip title={`DISTRIBUTION METRIC: ${targetField}`}>
                    {
                      targetField.length > 250 ? (`${targetField.slice(0, 200)}`) : (`${targetField}`)
                    }
                  </Tooltip>
                </Tag>
              );
            })
          }
        </div>
      </React.Fragment>
    );
  }

  formatTags = ({ tags }) => (
    <React.Fragment>
      {
        tags.filter(tag => tag !== null && tag !== undefined && tag !== '').map(tag => (
          <Tag color="#00AAFF">{tag}</Tag>
        ))
      }
    </React.Fragment>
  )


  formatActiveAlert= ({ data }) => {
    const activeAlert = data.alertConfigured;
    if (activeAlert > 0) {
      return (
        // <Tag color="#108ee9">
        //   <a href={`/alerts/${activeAlert}`} target="_blank" rel="noopener noreferrer">alert</a>
        // </Tag>
        <Tooltip title="alert is configured, click to open">
          <Button
            type="default"
            size="small"
            icon="check"
            shape="circle"
            onClick={() => openAlertLink(activeAlert)}
            style={{
              scale: '0.65',
            }}
          />
        </Tooltip>
      );
    }
    return (
      <span />
    );
  }

  toggleMetricsOnly(data) {
    update(data, { recordMetricsOnly: 1 - data.recordMetricsOnly })
      .then(() => {
        this.refreshDataGrid();
      })
      .catch((e) => {
        toastr.warning('Unable to update rule ', e);
      });
  }

  toggleActive(data) {
    update(data, { active: 1 - data.active })
      .then(() => {
        this.refreshContent();
      })
      .catch((e) => {
        toastr.warning('Unable to update rule ', e);
      });
  }


  toggleAlert(data) {
    update(data, { alertConfigured: 1 - data.active })
      .then(() => {
        this.refreshContent();
      })
      .catch((e) => {
        toastr.warning('Unable to update rule ', e);
      });
  }


  expandedRowRender = (record) => {
    const { condition,
      description,
      applicationMatch,
      match,
      rewrite,
      additionalLabels,
      patternLabels,
      tags, createdBy } = record;
    return (
      <Row
        style={{
          fontSize: '12px',
        }}
      >
        <Row>
          <Col span={4} className="lgq-col-key"> Application Match</Col>
          <Col span={20}>{applicationMatch}</Col>
        </Row>
        <Row>
          <Col span={4} className="lgq-col-key"> Description</Col>
          <Col span={20}>{description}</Col>
        </Row>
        <Row>
          <Col span={4} className="lgq-col-key"> Condition</Col>
          <Col span={20}>
            <Syntax language="json5" code={condition} />
          </Col>
        </Row>


        {
            match !== '' && (
              <Row>
                <Col span={4} className="lgq-col-key"> Match</Col>
                <Col span={20}>
                  <Syntax language="regex" code={match} />

                </Col>
              </Row>
            )
          }


        {
            rewrite !== '' && (
              <Row>
                <Col span={4} className="lgq-col-key"> Rewrite</Col>
                <Col span={20}>{rewrite}</Col>
              </Row>
            )
          }

        {
         patternLabels.length > 0 && (
         <Row>
           <Col span={4} className="lgq-col-key"> Pattern Match</Col>
           <Col span={20}>
             <React.Fragment>
               {
              patternLabels.map(label => (
                <Syntax

                  code={label.pattern}
                  language="regex"
                />
              ))
            }
             </React.Fragment>
           </Col>
         </Row>

         )
        }
        {
          (additionalLabels !== '' && additionalLabels !== null) ?
            (
              additionalLabels.labels.length !== 0 && (
              <Row>
                <Col span={4} className="lgq-col-key"> Labels</Col>
                <Col span={20} style={{ display: 'flex' }} className="additinal-label-tags">
                  <this.formatAdditionalLabels
                    data={record}
                  />
                </Col>
              </Row>
              )
            ) : null
        }
        {
          record.level !== '' && (
          <Row>
            <Col span={4} className="lgq-col-key"> Level</Col>
            <Col span={20}>
              <LogiqTags
                name={record.level}
                borderColor={levelColors[record.level]}
              />
            </Col>
          </Row>
          )}
        {
            createdBy !== '' && (
            <Row>
              <Col span={4} className="lgq-col-key"> Created By</Col>
              <Col span={20}>{createdBy}</Col>
            </Row>
            )
          }
        {
          tags !== '' && tags.length !== 0 && (
            <Row>
              <Col span={4} className="lgq-col-key"> Tags</Col>
              <Col span={20} style={{ display: 'flex' }}>
                <this.formatTags tags={tags} />
              </Col>
            </Row>
          )
        }
        <Row>
          <Col span={4}>Alert</Col>
          <Col span={20}>
            <this.formatActiveAlert data={record} />
          </Col>
        </Row>

      </Row>
    );
  }


  paginationChange = (offset) => {
    const { filter } = this.state;
    filter.offset = this.state.filter.count * (offset - 1);
    this.setState({ filter }, () => this.fetchRules());
  }

  doFilter = (filterField) => {
    // const tempFiltered = { ...filterField };
    // delete tempFiltered.count;
    // delete tempFiltered.offset;
    const tempFilters = {};

    const { filter } = this.state;
    if ('searchKeyword' in filterField) {
      tempFilters.search = filterField.searchKeyword;
    }
    if ('levels' in filterField) {
      tempFilters.level = filterField.levels;
    }

    if ('groups' in filterField) {
      tempFilters.groupNames = filterField.groups;
    } else {
      if ('filter' in filter) {
        const { groupNames } = filter.filter;
        if (groupNames && groupNames.length > 0) {
          tempFilters.groupNames = [...groupNames];
        }
      }
    }

    if ('ruleType' in filterField && typeof filterField.ruleType === 'string') {
      // if (filterField.ruleType === 'seim') {
      //   tempFilters.seimRule = true;
      // } else {
      //   tempFilters.seimRule = false;
      // }
      tempFilters.ruleType = filterField.ruleType;
    } else {
      // tempFilters.extRuleType = this.props.extRuleType || '';
      tempFilters.ruleType = this.props.ruleType || '';
    }

    filter.filter = tempFilters;
    filter.offset = 0;
    this.setState({ filter }, () => this.refreshContent());
  }


  handleTableChange = (pagination, filters, sorter) => {
    const { current } = pagination;
    const { filter } = this.state;
    filter.offset = this.state.filter.count * (current - 1);
    if (Object.keys(sorter).length > 0) {
      const { columnKey, order } = sorter;
      const sortOrder = order === 'ascend' ? 'ASC' : 'DESC';
      const sort = {
        attribute: columnKey,
        order: sortOrder,
      };
      filter.sort = { ...filter.sort, ...sort };
    }

    this.setState({ filter }, () => this.refreshContent());
  }

  render() {
    return (
      <Row className="logiq-table-list">
        <Row className="logiq-data-filter logiq-catlog-filter">
          <Col span={24}>
            <Filter
              disableTimeRangeFilter
              enableRuleGroupsFilter
              filter={this.state.filter}
              placeholder="Search..."
              onFilter={this.doFilter}
              handleNewEvent={this.handleNewEvent}
              groupType="rules"
              reloadComponent={this.refreshContent}
              showRuleType={false}
            />
          </Col>

        </Row>
        <Row className="logiq-data-table-row">
          <Col span={24}>
            <Table
              className="logiq-data-table"
              size="default"
              dataSource={this.state.rules}
              pagination={{
                defaultPageSize: this.state.filter.count,
                total: this.state.totalCount,
                current: parseInt(this.state.filter.offset / this.state.filter.count, 10) + 1,
              }}
              onChange={this.handleTableChange}
              showHeader
              // tableLayout="fixed"
              expandedRowRender={this.expandedRowRender}
              loading={this.state.tableLoading}
            >
              <Column
                sorter
                title="Name"
                key="name"
                ellipsis
                width="40%"
                render={(text, record) => (
                  <span>
                    {record.name}
                  </span>
                )}
              />


              <Column
                sorter
                title="Application"
                key="applicationMatch"
                ellipsis
                width="25%"
                render={(text, record) => (
                  <span>
                    {record.applicationMatch}
                  </span>
                )}
              />
              <Column
                sorter
                title="Active"
                key="active"
                width="15%"
                render={(text, record) => (
                  <span>
                    <Checkbox
                      checked={parseInt(record.active, 10) === 1}
                      onClick={() => this.toggleActive(record)}
                    />

                  </span>
                )}
              />

              <Column
                sorter
                title="Created"
                key="createdAt"
                ellipsis
                width="15%"
                render={(text, record) => (
                  <span>
                    {
                      record.createdAt.length < 13 ? (
                        <span>
                          {moment(parseInt(record.createdAt * 1000, 10)).fromNow()}
                        </span>
                      ) : (
                        <span>
                          {moment(parseInt(record.createdAt, 10)).fromNow()}
                        </span>
                      )
                   }

                  </span>
                )}
              />

              <Column
                title=""
                key=""

                render={(text, record) => (
                  <Dropdown overlay={<this.ruleMoreMenu record={record} />} placement="bottomLeft">
                    <Icon
                      type="more"
                      style={{
                        color: '#000',
                        fontSize: '16px',
                      }}
                    />
                  </Dropdown>
                )}
              />


            </Table>
            <div>
              {
            this.state.showAlertOnEvent ? (

              <AlertOnEvent
                eventName={this.state.name}
                visible={this.state.showAlertOnEvent}
                handleCancel={this.handleAlertModalCancel}
                alertData={this.state.alertData}
                refreshGrid={this.refreshDataGrid}
              />
            ) : null
          }
            </div>
            <div>
              {
                this.state.showEditRuleModal && (
                <EditRuleModal
                  record={this.state.currentRecord}
                  visible={this.state.showEditRuleModal}
                  handleCancel={this.handleEditRuleModalCancel}
                  refreshContent={this.refreshContent}
                  isActiveRules
                />
                )
              }

            </div>
          </Col>
        </Row>

      </Row>
    );
  }
}

export default PackRulesList;
