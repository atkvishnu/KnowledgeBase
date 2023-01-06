

In EventRule.js file

`eventDescription` is being pushed as a prop to the parent component (`EventModal.js`) .


```
eventDescription: {
    "name": "",
    "level": "",
    "description": "",
    "groupName": "antivirus",
    "namespace": "flash:ns2"
}
```

We have to change this namespace(string) to an array of strings, backend changes will also be needed!

```
grep "Namespace*"
```

- Check how eventDescription is being manipulated throughout both of these files.

- Give a toggle for making it an multi Select?, otherwise use the old logic.


> Similar to the additionalLabels change, will need to change `groupName: eventDescription.groupName,` from an string to an array.

> in backend, eventRules.proto, change groupName from string to repeated strings, and handle breaking changes likewise.




