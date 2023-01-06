

Created by: Kumar Vishnu
Created time: October 16, 2022 11:19 PM
Last edited by: Kumar Vishnu
Last edited time: November 3, 2022 10:00 AM


backend problem in: 
- event_processor.go (check for "AdditionalLabels")
- 






```go
***HEADERS:***
Request URL: http://localhost:8081/v1/eventRules
Request Method: POST
Status Code: 200 OK
Remote Address: 127.0.0.1:8081
Referrer Policy: strict-origin-when-cross-origin

access-control-allow-origin: http://localhost:8081
connection: close
content-length: 12
content-type: application/json
date: Tue, 18 Oct 2022 09:37:12 GMT
grpc-metadata-content-type: application/grpc
X-Powered-By: Express

Accept: application/json, text/plain, */*
Accept-Encoding: gzip, deflate, br
Accept-Language: en-GB,en-US;q=0.9,en;q=0.8
Connection: keep-alive
Content-Length: 464
Content-Type: application/json;charset=UTF-8
Cookie: _ga=GA1.1.210132511.1663079000; x-api-key=eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3MiOltdLCJhdWQiOiJsb2dpcS1jbGllbnRzIiwianRpIjoiOTQ3ODUzZTctYzU5ZC00NjBhLTg0NmQtY2U5MjE4NzY5MjM2IiwiaWF0IjoxNjY2MDg1NDM2LCJpc3MiOiJsb2dpcS1jb2ZmZWUtc2VydmVyIiwibmJmIjoxNjY2MDg1NDM2LCJzdWIiOiJmbGFzaC1hZG1pbkBmb28uY29tIiwiVWlkIjoxLCJyb2xlIjoiYWRtaW4ifQ.FsTmftUvfLoD92INMr2cycCS6soYUcrRDRqu5rk1hd9sO__viVUQYJJB3ONRwD334oyhUj8cQTS9GfB49QmJ-gGo644UZHih9YZgqAQPu1cd7B1NmEFJVqM4YMny5-1bnutDbXyaEoCRuiUU2TntRWYm4TYnxgt5qAcO6NPVz2Gj5K-98tCD2CfbgGtJJTjWf3nOPwV3e7e6SJcQCfIj0IggSIXQm7iA7JRCHmRCag8tcZQrv5d2nd_GL-CcAxKjy6CML0zlptIuJbov5cLmieao6PJceAa0LPURW2xaVhtAblKfhzlyy0KScCmdDL7NTRnCcgugPzQTET71r28Hbg; remember_token=1-5693cbc25f7956e50845bdb010090187|abe3fcf573837180c73233bf578dc7c0ff63145373cf8fd4a68f6a055db427628df215b552f11fe3857a98f64a5462f8d27046d2f1fd61ab893f80126795e61f; session=.eJwlzsEKAzEIBNB_ybkFjbom-zMlRqW97nZPpf_eQG_DMDDvUx55xPks-_u44lYeLy97UVDyKsk061BGhQpcR3CG6ZQgklUzJK9IKehEtQtCWiJohNHssOnGTbxV5oix5uaU1rBzMFQbKm0YstaGqesqzdkRTLEsyHXG8dfgXbZO0-YSaZctBBqLuQECdMCm5fsDxuM2WA.FjADvA.iJdkdz4fVsVw9Bm73j3SdHwWqxw; _ga_YEFDT6TH8X=GS1.1.1666085432.49.1.1666085832.0.0.0
Host: localhost:8081
Origin: http://localhost:8081
Referer: http://localhost:8081/explore
sec-ch-ua: "Chromium";v="106", "Google Chrome";v="106", "Not;A=Brand";v="99"
sec-ch-ua-mobile: ?0
sec-ch-ua-platform: "Linux"
Sec-Fetch-Dest: empty
Sec-Fetch-Mode: cors
Sec-Fetch-Site: same-origin
User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36
```

```go
***REQUEST PAYLOAD:***

{
  "groupName": "syslog",
  "name": "forward_test_1__e1015e",
  "level": "",
  "description": "forward_test_1-endpoint-test",
  "namespace": "flash:ns3",
  "applicationMatch": "app3",
  "active": 1,
  "ruleType": "REGEXDROP",
  "recordMetricsOnly": 1,
  "immutable": 0,
  "tags": [],
  "recordTimeField": 0,
  "eventMetrics": [],
  "additionalLabels": [
    "kubernetes_annotations_cni_projectcalico_org/podip",
    "mdc.instance_name",
    "stringarr2"
  ],
  "patternLabels": [],
  "condition": "(Namespace=='flash:ns3') && (AppName=~'app3')"
}
```

- I will need to query additionalLabels column (from `eventrules` table) for corresponding name/description (or both)?
- Check if additionallabel column’s value is an array, if it is then make it an object having 2 k-v pairs like this:

```go
Backward Compatible: ["a", "b", ......]

New Structure:
{
	"labels": ["a", "b", ......],
	"renamedLabels": {
			"a": "aa",
			"b": "bb"
	}
}
```

- 

# TODO

- EventModal is the parent component. and EventRule is the child component.
- `additionalLabels` is getting used as a prop between both the parent and child component.
- make a same state in parent and child component. like `additionalLabels`.

For context:

- do `cdfe` and `grep "setAdditionalLabels"`
- Look and analyze how same state is added to the 2 files. `77: const [additionalLabels, setAdditionalLabels] = React.useState([]);` in EventRule.js

and `109: const [additionalLabels, setAdditionalLabels] = React.useState([]);` in EventModal.js

---

---

# Backend Changes:

While sending this object of arrays as a request, the backend gave an error.

`'json: cannot unmarshal object into Go value of type []json.RawMessage'`

Previously it was parsing an array of strings.

[23/10/2022 1:40 AM] Ranjan Parthasarathy: Can you send as an array

[23/10/2022 1:40 AM] Ranjan Parthasarathy: Encapsulate in array of length 1

I tried, but inside the array we have multiple arrays.

Ranjan: Can we add selection of labels to rename vs shows all labels

I need to push this as a array of length 1?

But previously we were pushing a array like this:
`["_size","correlationid","kubernetes_annotations_cni_projectcalico_org/podip"]`
This array's length is 3.

This was getting inserted in the DB properly

[23/10/2022 1:54 AM] Ranjan Parthasarathy: Guess you will need to changed backend api

[23/10/2022 1:55 AM] Ranjan Parthasarathy: Add a new one with new signature

```go
+message AddLabels {
+  repeated string labels = 1;
+  map<string, string> renamedLabels = 2;
+  map<string, string> customLabels = 3;
+}
+
 message EventRule {
   string name = 1;
   string description = 2;
@@ -82,7 +88,7 @@ message EventRule {
   int32 alertConfigured = 11;
   int32 recordMetricsOnly = 12; // used as boolean, if 1 only record the event counter with prometheus and NOT store event in db
   repeated EventMetric eventMetrics = 13;
-  repeated string additionalLabels = 14;
+  AddLabels additionalLabels = 14;
   repeated PatternLabel patternLabels = 15;
   repeated string tags = 16;
   int64 createdAt = 17;
```

```go
protoc 
```

without related

```go
{
    "labels": [
        "_size",
        "_some_int",
        "correlationid",
        "kubernetes_annotations_cni_projectcalico_org/podip"
    ],
    "renamedLabels": {
        "_size": "test35",
        "_some_int": "test35",
        "correlationid": "test35",
        "kubernetes_annotations_cni_projectcalico_org/podip": "k8s"
    },
    "customLabels": {
        "correlationid": "test35",
        "stringarr2": "test35",
        "stringarr3": "test35"
    }
}
```

```go
ERRO[2022-10-26T22:27:48.341155527+05:30] descriptor Desc{fqName: "logiq_ae_test35__e1184e_count", help: "Total no of events created for test35__e1184e", constLabels: {}, variableLabels: [__size__some_int_correlationid_kubernetes_annotations_cni_projectcalico_org_podip_ map__size_test35__some_int_test35_correlationid_test35_kubernetes_annotations_cni_projectcalico_org_podip_k8s_ map_correlationid_test35_stringarr2_test35_stringarr3_test35_ l2m_namespace application_name]} is invalid: "__size__some_int_correlationid_kubernetes_annotations_cni_projectcalico_org_podip_" is not a valid label name for metric "logiq_ae_test35__e1184e_count"  File=flash/event_processor/event_processor.go Line=1858
ERRO[2022-10-26T22:27:48.341205897+05:30] Invalid metrics name: Prometheus alert metrics for test35__e1184e not registered  File=flash/event_processor/event_processor.go Line=1865
```

labels: [map[stringarr:a1 stringarr2:a3 stringarr3:a2] [_size correlationid isbool] map[_size:asd correlationid:dsa isbool:a1]]

[map[stringarr:qwe stringarr2:wer stringarr3:erty] 

[*some_int isbool mdc.client_ip] map[some_int:asd isbool:dsa mdc.client_ip:asd]]*

*map[stringarr:qwe stringarr2:wer stringarr3:erty]* 

*(label) ---------> map_stringarr_qwe_stringarr2_wer_stringarr3_erty (SanitizedString) ---------> map[] (labelsMap)
[some_int isbool mdc.client_ip]* 

*(label) ---------> some_int_isbool_mdc_client_ip (SanitizedString) ---------> map[map_stringarr_qwe_stringarr2_wer_stringarr3_erty:1] (labelsMap)
map[some_int:asd isbool:dsa mdc.client_ip:asd]* 

*(label) ---------> map__some_int_asd_isbool_dsa_mdc_client_ip_asd (SanitizedString) ---------> map[some_int_isbool_mdc_client_ip:1 map_stringarr_qwe_stringarr2_wer_stringarr3_erty:1] (labelsMap)
[map_stringarr_qwe_stringarr2_wer_stringarr3_erty]* 

*(labels after appending) -------> [map_stringarr_qwe_stringarr2_wer_stringarr3_erty* *some_int_isbool_mdc_client_ip] (labels after appending) -------> [map_stringarr_qwe_stringarr2_wer_stringarr3_erty* *some_int_isbool_mdc_client_ip map__some_int_asd_isbool_dsa_mdc_client_ip_asd*] (labels after appending) ------->

```go
fields:{key:"customLabels"  value:{struct_value:{fields:{key:"_size"  value:{string_value:"ewq"}}  fields:{key:"correlationid"  value:{string_value:"ert"}}}}}  fields:{key:"labels"  value:{list_value:{values:{string_value:"correlationid"}  values:{string_value:"kubernetes_annotations_cni_projectcalico_org/podip"}}}}  fields:{key:"renamedLabels"  value:{struct_value:{fields:{key:"correlationid"  value:{string_value:"123"}}  fields:{key:"kubernetes_annotations_cni_projectcalico_org/podip"  value:{string_value:"asd"}}}}}
```

```go
map[customLabels:map[stringarr:asd stringarr2:ewq stringarr3:ert] labels:[_some_int isbool kubernetes_annotations_cni_projectcalico_org/podip] renamedLabels:map[_some_int:asd isbool:dsas kubernetes_annotations_cni_projectcalico_org/podip:qwe]]
```

```go
map[customLabels:struct_value:{fields:{key:"isbool" value:{string_value:"eqweerter"}} fields:{key:"mdc.client_ip" value:{string_value:"werwer"}}} 
labels:list_value:{values:{string_value:"_size"} values:{string_value:"_some_int"} values:{string_value:"correlationid"}} 
renamedLabels:struct_value:{fields:{key:"_size" value:{string_value:"asd"}} fields:{key:"_some_int" value:{string_value:"dsa"}} fields:{key:"correlationid" value:{string_value:"asd"}}}]
```

{
"labels": [
"_size",
"_some_int",
"correlationid"
],
"renamedLabels": {
"_size": "asd",
"_some_int": "dsa",
"correlationid": "asd"
},
"customLabels": {
"isbool": "eqweerter",
"mdc.client_ip": "werwer"
}
}

---

---

---

---

---

```go
~/projects/redash-fork feature/LD-726-rename-rule
❯ grep "additionalLabels"
client/app/pages/rules/RulesList.jsx
64:  if ('additionalLabels' in item && typeof (item.additionalLabels) === 'string') {
65:    item.additionalLabels = item.additionalLabels.split(',').map(ele => ele.trim());
349:    // console.log('from formatAdditionalLabels-----> ', typeof data.additionalLabels, Array.isArray(data.additionalLabels));
355:           data.additionalLabels.labels.map(label => (
488:      additionalLabels,
491:    // console.log(record.additionalLabels);
492:    // console.log(record.additionalLabels.labels, typeof additionalLabels.labels, additionalLabels.labels.length);
560:          additionalLabels !== '' ?
561:            (additionalLabels.labels.length !== 0 && (

client/app/pages/rules/EditRuleModal.jsx
33:      additionalLabelsArr: [],
44:      allowedFields.additionalLabels = { allowEmpty: true, type: 'array', fieldType: 'select' };
46:      delete allowedFields.additionalLabels;
192:     if (field === 'additionalLabels') {
193:       this.state.additionalLabelsArr = this.props.record[field].labels;
194:       console.log(this.state.additionalLabelsArr);
200:         required={field !== 'additionalLabels'}
205:             rules: [{ required: field !== 'additionalLabels', message: `Please input a valid ${field}` }],

client/app/pages/bundles/catalog/rules/PackRulesList.jsx
45:  if ('additionalLabels' in item && typeof (item.additionalLabels) === 'string') {
46:    item.additionalLabels = item.additionalLabels.split(',').map(ele => ele.trim());
323:           data.additionalLabels.map(label => (
456:      additionalLabels,
525:          additionalLabels !== '' && additionalLabels.length !== 0 && (

client/app/components/dashboards/analyze.jsx
47:    const { additionalLabels } = l2mData;
48:    const label = additionalLabels[0] || '';
78:    const { namespace, application, additionalLabels, name } = log2metricData;
94:        let label = additionalLabels[0] || '';

client/app/components/event-modal/EventRule.js
78:  const [additionalLabels, setAdditionalLabels] = React.useState([]);
629:      handleAdditionalLabels([...additionalLabels]);
638:      handleAdditionalLabels([...additionalLabels]);
702:              value={additionalLabels}
741:          additionalLabels.map(data => (
1174:                  value={additionalLabels && additionalLabels.length > 0 ? additionalLabels[0] : ''}
1221:                value={additionalLabels}
1258:                  value={additionalLabels}
1300:                  additionalLabels.map(data => (

client/app/components/event-modal/EventVis.js
25:  additionalLabels,
65:            .filter(_d => additionalLabels.indexOf(_d.label) < 0);

client/app/components/event-modal/RulePreview.js
15:  additionalLabels }) => {
20:    if (additionalLabels.length > 0) {
21:      const __additionalLabels = additionalLabels.map(label => sanitizeLabel(label));
23:      sum by (${__additionalLabels.join(', ')}) (increase(logiq_ae_${name}_count[${eventPeriod}])${operator}${occurances}) rearming alert every ${rearm}s,
34:  }, [additionalLabels, name]);

client/app/components/event-modal/EventModal.js  ***DONE***

```

---

-

---

-

---

# Backend changes in these files to handle AdditionalLabels and additionalLabels:

```go
❯ grep "additionalLabels"                                                     
api/swagger/api/proto/eventRules.swagger.json
587:        "additionalLabels": {

api/v1/eventRules/eventRules.pb.go
311:    AdditionalLabels  *structpb.Struct `protobuf:"bytes,14,opt,name=additionalLabels,proto3" json:"additionalLabels,omitempty"`
1866:   24, // 3: eventRules.EventRule.additionalLabels:type_name -> google.protobuf.Struct

api/proto/eventRules.proto
92:  google.protobuf.Struct additionalLabels = 14;

api/server/eventRules.go
207:                    var additionalLabels interface{}
211:                    if scanErr := eventRulesResult.Scan(&e.Name, &e.Description, &e.Condition, &e.Match, &e.Rewrite, &e.Level, &e.GroupName, &active, &immutable, &e.RuleType, &e.ApplicationMatch, &e.AlertConfigured, &e.RecordMetricsOnly, &eventMetrics, &additionalLabels, &tags, &e.CreatedAt, &e.CreatedBy, &e.ExtRuleType, &e.Namespace, &patternLabels); scanErr != nil {
218:                            if additionalLabelsstr, ok := additionalLabels.(string); ok {
220:                                    if additionalLabelsstr != "null" {
221:                                            err := json.Unmarshal([]byte(additionalLabelsstr), &tempAdditionalLabels)
367:    additionalLabels, err := json.Marshal(req.AdditionalLabels)
374:    ruleObject["additionalLabels"] = string(additionalLabels)
413:            AdditionalLabels:  string(additionalLabels),
496:    var additionalLabels []byte
499:            additionalLabels, err = json.Marshal(req.AdditionalLabels)
523:    ruleObject["additionalLabels"] = string(additionalLabels)
546:            AdditionalLabels:  string(additionalLabels),
668:                    q = q.Set("AdditionalLabels", string(additionalLabels))

config/event_rules/fortinet.yaml
55:    additionalLabels: '["logid","type","subtype","level","vd","srcip","srcport","srcintf","srcintfrole","dstip","dstport","dstintf","dstintfrole","srccountry","dstcountry","sessionid","proto","action","policyid","service","trandisp","app","duration","sentbyte","rcvdbyte","sentpkt","rcvdpkt","appcat","logdesc","hostname","msg"]'

config/event_rules/k8s.yaml
9:  additionalLabels: '["kubernetes.container_hash","kubernetes.docker_id","kubernetes.labels.controller-revision-hash","kubernetes.container_image"]'
15:  additionalLabels: '["kubernetes.host"]'
21:  additionalLabels: '["kubernetes.labels.pod-template-generation","kubernetes.pod_name","kubernetes.pod_id"]'
27:  additionalLabels: '["kubernetes.labels.security.istio.io/tlsmode","kubernetes.annotations.sidecar.istio.io/status","kubernetes.labels.service.istio.io/canonical-name","kubernetes.labels.service.istio.io/canonical-revision"]'
33:  additionalLabels: '["kubernetes.annotations.kubectl.kubernetes.io/default-container","kubernetes.annotations.kubectl.kubernetes.io/default-logs-container"]'
39:  additionalLabels: '["kubernetes.annotations.prometheus.io/port","kubernetes.annotations.prometheus.io/scrape","kubernetes.annotations.prometheus.io/path"]'
45:  additionalLabels: '["kubernetes.annotations.kubernetes.io/psp","kubernetes.annotations.iam.amazonaws.com/role","kubernetes.annotations.checksum/api_key","kubernetes.annotations.checksum/autoconf-config","kubernetes.annotations.checksum/checksd-config","kubernetes.annotations.checksum/clusteragent_token","kubernetes.annotations.checksum/confd-config","kubernetes.annotations.checksum/install_info"]'

config/event_rules/cloudtrail.yaml
269:    additionalLabels: '["responseelements.credentials.sessiontoken"]'

config/event_rules/datadog.yaml
9:    additionalLabels: '["dd.env","dd.service","dd.span_id","dd.trace_id","dd.version","kubernetes.labels.tags.datadoghq.com/version","kubernetes.labels.tags.datadoghq.com/service","kubernetes.labels.tags.datadoghq.com/env"]'

wings/utils.go
26://           name, additionalLabels, err := event_processor.GetEventRuleByPartialName(context.Background(), eventSequence)
31://           var additionalLabelsArray []string
32://           if additionalLabels != "" {
33://                   err := json.Unmarshal([]byte(additionalLabels), &additionalLabelsArray)
38://           for _, al := range additionalLabelsArray {

migrations/migrations_definitions.go
170:                                            logEntry.ContextLogger().Debugf("Found column : %s in %s", "additionalLabels", event_processor.EventRuleDefinition{}.GetTableName())

event_processor/event_processor.go
847:                                                            additionalLabels := prometheus.Labels{
879:                                                                                    additionalLabels[label] = fv[0]
884:                                                                                            additionalLabels[label] = fv
909:                                                                            additionalLabels[k] = v
915:                                                                    _, found := additionalLabels[label]
935:                                                                            additionIndexLabel := fmt.Sprintf("%v_%v_%v", eventFirstIndex, label, additionalLabels[label])
949:                                                                    if c, err := (*event.EventRulePromCounter).GetMetricWith(additionalLabels); err == nil {
1003:                                                                                                                           // (*event.EventMetricPromGauge).With(additionalLabels).Set(val)
1010:                                                                                                                           // (*event.EventMetricPromHist).With(additionalLabels).Observe(val)
1050:                                                                                                                           // (*event.EventMetricPromGauge).With(additionalLabels).Set(f)
1066:                                                                                                                           // (*event.EventMetricPromHist).With(additionalLabels).Observe(f)
1116:                                                                                                                   // (*event.EventMetricPromGauge).With(additionalLabels).Set(t)
1131:                                                                                                                   // (*event.EventMetricPromHist).With(additionalLabels).Observe(t)
1794:                   ruleObject["additionalLabels"] = string(e.AdditionalLabels)
1834:func registerPrometheus(alertName string, additionalLabels []string) *prometheus.CounterVec {
1840:   for _, label := range additionalLabels {
1874:   //for _, label := range additionalLabels {
1904:   //for _, label := range additionalLabels {

event_processor/eventRules.go
36:     AdditionalLabels  string `mapstructure:"additionalLabels" json:"additionalLabels"`

event_processor/eventRuleCache.go
56:             var additionalLabels []*string
61:                             err := json.Unmarshal([]byte(e.AdditionalLabels), &additionalLabels)
65:                                     for _, label := range additionalLabels {
67:                                             //fmt.Println("Added in additionalLabels---------> %v", labels)
81:                                             //fmt.Printf("Added in pbadditionalLabels---------> %v\n", labels)

~/go/src/bitbucket.org/logiqcloud/flash LD-727-Rename-Rule-Support* ≡
❯ grep "AdditionalLabels"
api/server/eventRules_test.go
34:                     want:  "SELECT Name,Description,Condition,Match,Rewrite,Level,GroupName,Active,Immutable,RuleType,ApplicationMatch,AlertConfigured,RecordMetricsOnly, EventMetrics, AdditionalLabels, Tags, CreatedAt, CreatedBy, ExtType, Namespace, PatternLabels  FROM EventRules WHERE tags Like '%last%' or tags Like '%test%' order by  GroupName asc, Name asc limit 20 offset 0;",
49:                     want:  "SELECT Name,Description,Condition,Match,Rewrite,Level,GroupName,Active,Immutable,RuleType,ApplicationMatch,AlertConfigured,RecordMetricsOnly, EventMetrics, AdditionalLabels, Tags, CreatedAt, CreatedBy, ExtType, Namespace, PatternLabels  FROM EventRules WHERE tags Like '%last%' order by  GroupName asc, Name asc limit 20 offset 0;",
64:                     want:  "SELECT Name,Description,Condition,Match,Rewrite,Level,GroupName,Active,Immutable,RuleType,ApplicationMatch,AlertConfigured,RecordMetricsOnly, EventMetrics, AdditionalLabels, Tags, CreatedAt, CreatedBy, ExtType, Namespace, PatternLabels  FROM EventRules WHERE  createdBy = 'tito'  order by  GroupName asc, Name asc limit 20 offset 0;",
79:                     want:  "SELECT Name,Description,Condition,Match,Rewrite,Level,GroupName,Active,Immutable,RuleType,ApplicationMatch,AlertConfigured,RecordMetricsOnly, EventMetrics, AdditionalLabels, Tags, CreatedAt, CreatedBy, ExtType, Namespace, PatternLabels  FROM EventRules WHERE  createdBy = 'tito' and ExtType = 'REWRITE'  order by  GroupName asc, Name asc limit 20 offset 0;",

api/server/eventRules.go
148:            "AdditionalLabels, "+
219:                                    var tempAdditionalLabels *structpb.Struct
221:                                            err := json.Unmarshal([]byte(additionalLabelsstr), &tempAdditionalLabels)
227:                                                    e.AdditionalLabels = tempAdditionalLabels
367:    additionalLabels, err := json.Marshal(req.AdditionalLabels)
413:            AdditionalLabels:  string(additionalLabels),
497:    if req.AdditionalLabels != nil {
499:            additionalLabels, err = json.Marshal(req.AdditionalLabels)
546:            AdditionalLabels:  string(additionalLabels),
667:            if len((req.AdditionalLabels).AsMap()) > 0 {
668:                    q = q.Set("AdditionalLabels", string(additionalLabels))

api/v1/eventRules/eventRules.pb.go
311:    AdditionalLabels  *structpb.Struct `protobuf:"bytes,14,opt,name=additionalLabels,proto3" json:"additionalLabels,omitempty"`
450:func (x *EventRule) GetAdditionalLabels() *structpb.Struct {
452:            return x.AdditionalLabels

wings/utils_test.go
36://                   `INSERT INTO EventRules (Name, AdditionalLabels)

event_processor/eventRules.go
36:     AdditionalLabels  string `mapstructure:"additionalLabels" json:"additionalLabels"`

event_processor/eventRuleCacheSync.go
169:    query := fmt.Sprintf("SELECT Name,Description,Condition,Match, Rewrite, Level,GroupName,Active,Immutable,RuleType,ApplicationMatch,AlertConfigured,RecordMetricsOnly, EventMetrics, AdditionalLabels, PatternLabels, ExtType, Namespace FROM EventRules where Name = '%s'", eventRuleName)
179:                            &e.AlertConfigured, &e.RecordMetricsOnly, &e.EventMetrics, &e.AdditionalLabels,
194:    query := fmt.Sprintf("SELECT Name,Description,Condition,Level,GroupName,Active,Immutable,RuleType,ApplicationMatch,AlertConfigured,RecordMetricsOnly,EventMetrics, AdditionalLabels, PatternLabels, ExtType, Namespace  FROM EventRules where GroupName = '%s'", groupName)
218:                            &e.AdditionalLabels,

event_processor/event_processor.go
114:                                            if v.EventDefinition.AdditionalLabels != "" {
115:                                                    err := json.Unmarshal([]byte(v.EventDefinition.AdditionalLabels), &eventLabels)
787:                                                    if event.EventDefinition.AdditionalLabels != "" {
788:                                                            if val, ok := EventLabelsMap.Load(event.EventDefinition.AdditionalLabels); ok {
791:                                                                    }).Tracef("from cache AdditionalLabels")
794:                                                                    err := json.Unmarshal([]byte(event.EventDefinition.AdditionalLabels), &eventLabels)
802:                                                                            EventLabelsMap.Store(event.EventDefinition.AdditionalLabels, eventLabels)
1325:                                   if event.EventDefinition.AdditionalLabels != "" {
1326:                                           if val, ok := EventLabelsMap.Load(event.EventDefinition.AdditionalLabels); ok {
1329:                                                   }).Tracef("from cache AdditionalLabels")
1332:                                                   err := json.Unmarshal([]byte(event.EventDefinition.AdditionalLabels), &eventLabels)
1340:                                                           EventLabelsMap.Store(event.EventDefinition.AdditionalLabels, eventLabels)
1562:                                                   "AdditionalLabels",
1586:                                                   definition.AdditionalLabels,
1739:           "AdditionalLabels, "+
1769:                   &e.AdditionalLabels,
1794:                   ruleObject["additionalLabels"] = string(e.AdditionalLabels)

event_processor/eventRuleCache.go
59:             if e.AdditionalLabels != "" {
60:                     if e.AdditionalLabels[0] == 91 {
61:                             err := json.Unmarshal([]byte(e.AdditionalLabels), &additionalLabels)
63:                                     logEntry.ContextLogger().Error("Un-marshalling error", err, " label: ", e.AdditionalLabels)
71:                     if e.AdditionalLabels[0] == 123 {
72:                             var structuredAdditionalLabels *structpb.Struct
73:                             err := json.Unmarshal([]byte(e.AdditionalLabels), &structuredAdditionalLabels)
75:                                     logEntry.ContextLogger().Error("Un-marshalling error", err, " label: ", e.AdditionalLabels)
78:                                     pbAdditionalLabels := structuredAdditionalLabels.AsMap()["labels"].([]interface{})
79:                                     for _, label := range pbAdditionalLabels {

event_processor/eventrulessvc.go
68:     query, args, err := psql.Select("Name", "AdditionalLabels").
```

-----------------------------



```
~/projects/redash-fork feature/LD-726-rename-rule
❯ grep "additionalLabels"
client/app/pages/rules/RulesList.jsx  DONE
client/app/pages/bundles/catalog/rules/PackRulesList.jsx  DONE
client/app/components/event-modal/EventModal.js    DONE
client/app/components/event-modal/EventRule.js   DONE
client/app/components/event-modal/RulePreview.js   DONE (NO CHANGE needed)(only for forwards page - query tab @ bottom of modal)
client/app/components/event-modal/EventVis.js   DONE (NO CHANGE needed) - used in EventModal.js additionalLabels is same
client/app/components/dashboards/analyze.jsx    DONE (NO CHANGE needed), additionalLabels is coming as an array


client/app/pages/rules/EditRuleModal.jsx
33:      additionalLabelsArr: [],
44:      allowedFields.additionalLabels = { allowEmpty: true, type: 'array', fieldType: 'select' };
46:      delete allowedFields.additionalLabels;
192:     if (field === 'additionalLabels') {
193:       this.state.additionalLabelsArr = this.props.record[field].labels;
194:       console.log(this.state.additionalLabelsArr);
200:         required={field !== 'additionalLabels'}
205:             rules: [{ required: field !== 'additionalLabels', message: `Please input a valid ${field}` }],
```

![[Pasted image 20221107162208.png]]

-   sanitize() function uses `typeof (item.additionalLabels) === ‘string’`, now it’s object of objects and arrays, previously also it was an object because it was an array.

Why is it only checking for item.additionalLabels as string?

Is it for some special edge case? Sanitize fn. is at 2 places, will make the similar changes at both the places?

```
const sanitize = (item) => {
  console.log('-> item before', item);
  // console.log('-> typeof item.additionalLabels.labels', typeof item.additionalLabels.labels);
  item.active = item.active ? 1 : 0;
  item.immutable = 0; // setting it explicitly but server should always ignore this;
  // item.recordMetricsOnly = item.recordMetricsOnly ? 0 : 1;
  item.alertConfigured = item.alertConfigured > 0 ? 1 : 0;

  if ('additionalLabels' in item && (item.additionalLabels !== null)
      && typeof (item.additionalLabels.labels) === 'string') {
    item.additionalLabels.labels = item.additionalLabels.labels.split(',').map(ele => ele.trim());
  }
  console.log('-> item after, item.additionalLables', item, item.additionalLabels);
  return item;
};
```


----------




Make changes in backend functyions

grep "AdditionalLabels"



git diff b5c7d01..a525bd6


placeholder={(field === 'additionalLabels' && this.props.record[field].label.length === 0) ? 'NO LABELS PRESENT' : `${field}*`}








```
var additionalLabels []*string  
var labels []string  
  
if e.AdditionalLabels != "" {  
   if e.AdditionalLabels[0] == 91 {  
      err := json.Unmarshal([]byte(e.AdditionalLabels), &additionalLabels)  
      if err != nil {  
         logEntry.ContextLogger().Error("Un-marshalling error", err, " label: ", e.AdditionalLabels)  
      } else {  
         for _, label := range additionalLabels {  
            labels = append(labels, *label)  
         }      }  
   }  
   if e.AdditionalLabels[0] == 123 {  
      var structuredAdditionalLabels *structpb.Struct  
      err := json.Unmarshal([]byte(e.AdditionalLabels), &structuredAdditionalLabels)  
      if err != nil {  
         logEntry.ContextLogger().Error("Un-marshalling error", err, " label: ", e.AdditionalLabels)  
      } else {  
         // extracting the labels from the array, array will still be coming inside the object  
         pbAdditionalLabels := structuredAdditionalLabels.AsMap()["labels"].([]interface{})  
         for _, label := range pbAdditionalLabels {  
            if label == " " {  
               continue  
            } else {  
               labels = append(labels, label.(string))  
               fmt.Println("label: ", labels)  
            }  
         }  
      }  
   }  
}
```























