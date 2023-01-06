LOGIQ.ai
After new release, 1 URL was not working because it had special characters. 
GET request was returning status code 400, bad request.

To resolve this, a fix was added where all the URL's were encoded.

Request URL: 
https://lq8.logiq.ai/v2/applications_v3?sortOrder=desc&sortAttribute=lastSeen&namespaces=dev:goodmeetingsai&lastSeenStartTime=1669745054&lastSeenEndTime=1669831454&count=15&offset=0&applications=%{[resource][labels][service_name]}

error: "invalid URL escape \"%{[\""


```js
diff --git a/client/app/pages/logs/LogsList.jsx b/client/app/pages/logs/LogsList.jsx
index 5ff1ae375..92fb1d2c1 100644
--- a/client/app/pages/logs/LogsList.jsx
+++ b/client/app/pages/logs/LogsList.jsx
@@ -259,7 +259,7 @@ class LogsList extends React.Component {
         _timeRangeFilter.from = timeRangeFilter.from;
         _timeRangeFilter.to = timeRangeFilter.to;
       }
-      const ns = `&namespaces=${namespace}`;
+      const ns = `&namespaces=${encodeURI(namespace)}`;
       if (ns !== '') {
         URL = `${URL}${ns}`;
       }
@@ -277,7 +277,7 @@ class LogsList extends React.Component {
       }
 
       if (name) {
-        URL = `${URL}&applications=${name}`;
+        URL = `${URL}&applications=${encodeURI(name)}`;
       }
       const response = await (await axios.get(URL)).data;

```
