- Only able to delete some dashboards, 500 code (may be related to archive or created with Data Explorer)
- If you delete a query while inside it nothing happens and you stay on the same page but if you go back to queries it's gone
- If i archive a query i can't remove the archive status like i can with dashboards
- Unable to import dashboards
- Can't clone checks, 400 code, check got cloned anyway but didn't save changes
- Can't edit checks, 400 code
- Data Explorer - can't add logs tab
- Creating a dashboard from Data Explorer does not include all tabs you created, mine was created with Test wich is there by default, Delault tab with one widget added, the alert tab was not created
- Unable to delete rules, no button for it
- Filtering namespaces show all namespaces in the list but if you select one only 2 will remain
- Filtering groups show words separated by a space with each word having a capital letter at the start but when you select them the name may be different as it would show the real name then
- Manage columns does not apply when you expand a pipeline (not sure if this is intended)
- Creating a new pipeline in visualize pipeline returns the following error code: Failed to fetch the pipeline config.
- This also happens if you click on refresh after adding the pipeline
- Unable to add multiple users to a group at the same time - [@Naman Mishra](https://apica.slack.com/team/U06V4JYM55Z)
- Unable to see users in the list using the api if the user is disabled
- Unable to delete users, 500 code
- Query snippets say: Created by undefined
- In Tag Management the previous page arrow overlaps with Manage Columns
- ~~Unable to upload certificates in Certificate Management - [@Anurag Chaturvedi](https://apica.slack.com/team/U07BZ7CLVS6)~~












Create New Dashboard




# Ascent v2.10.3

coffee - v3.16.5
flash - v3.15.4
@Manchal @Brian Dunavant Please make sure that this version is getting deployed to all the customer production environments without any delay.

Here is the CM ticket for this change. https://apicasystems.atlassian.net/browse/CM-928

Let's make sure SEB is getting this 