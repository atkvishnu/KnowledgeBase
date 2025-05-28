# Authorization with <WithAuthorization> Component

#### The <WithAuthorization> component ensures access control enforcement by integrating with the Ascent Enforcer. It verifies user permissions before executing specific actions.

### Configuration

This component requires:

- `enforcerId`: Defines the authorization service (built-in/ascent-enforcer).
- `mode`: Determines behavior (disable, hide).
- `soa`: Security Object Array defining authorization rules.


### Props
| Prop       | Type            | Description                                                                            |
|------------|-----------------|----------------------------------------------------------------------------------------|
| enforcerId | string          | ID of the enforcer service (built-in/ascent-enforcer).                                 |
| mode       | 'disable'       | Defines behavior (disable, hide).                                                      |
| soa        | Array<[string, string] \| [string, string, string]> | Defines authorization rules in pairs of [resource, action] or [key, resource, action]. |
| children   | React.ReactNode | Encapsulates UI elements the require authorization checks.                             |
| isAllowed  | boolean \| null | If null, authorization is determine via useAuthorization({ enforcerId, soa })    |


Example Usage
Copy
<WithAuthorization
enforcerId="built-in/ascent-enforcer"
mode="disable"
soa={[
["checks:/*", "delete"],
[`checks/${checkData.check_id}`, "delete"]
]}
>
<button>Delete Check</button>
</WithAuthorization>
How It Works
The soa array defines authorization rules:

"checks:/*", "delete" → Users must have permission to delete any checks.

"checks/${checkData.check_id}", "delete" → Users must have permission to delete a specific check.

The mode:

"disable" → Disables the component if access is denied.

"hide" → Hides the component if access is denied.

The enforcerId defines which authorization service is used to validate access rules.

Best Practices
✔ Ensure soa rules are correctly structured. ✔ Use disable mode for UI elements that should not be accessible. ✔ Use hide mode for sensitive actions that should remain invisible to unauthorized users. ✔ Follow standard authorization practices for better security.

Dynamic Data-Driven Access Control
1. Initializing soa with useState
   To dynamically manage authorization rules:

Copy
const [soa, setSoa] = useState<([string, string] | [string, string, string])[]>(MANAGE_CHECK_CONTROLS);
soa (Security Object Array): Defines the authorization rules for different actions.

useState: Manages soa, allowing dynamic updates as needed.

Default Value (MANAGE_CHECK_CONTROLS):

This represents predefined security rules.

Each item follows [resource, action] or [key, resource, action] format.

Example:

Copy
const MANAGE_CHECK_CONTROLS = [
["checks:/*", "delete"],
[`checks/${checkData.check_id}`, "delete"]
];
2. Getting Access Control Permissions with useAccessControl

Copy
const { accessControl } = useAccessControl(soa);
useAccessControl(soa):

Calls an access control hook to evaluate permissions based on the defined soa rules.

Returns an accessControl object that maps resources to boolean values (true for allowed, false for denied).

Example output:

Copy
{
"checks:/*": true,
"checks/12345": false
}
Dynamic Updates:

If soa is modified using setSoa, permissions are re-evaluated.

End-to-End Flow
Load soa → Retrieve security rules.

Apply useAccessControl(soa) → Fetch access control values.

Check accessControl → Determine allowed actions for resources.
