# CL draft related to `feature/rename-rule`.

### AGENDA:
- Add a new rule to the FORWARD rules tab. (Rules >> Kubernetes)
- Toggle (antd's Switch component) needs to be switched to turn on this feature.
- After switching the toggle input fields will be rendered for each selected tags.
- Rename tags to a new keyName to save up on the data being forwarded to different data integrations.

- We have the data being stored and interacted from the PostgresDB's `eventrules` table.

- Need to add a new column named `renamedFields` to `eventrules` table.

> `select * from eventrules where ruletype='FORWARD'`

