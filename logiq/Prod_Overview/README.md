# lq5955.logiq.ai
# dev.logiq.ai

- Backend Server: flash {`golang`}

- Frontend : Coffee server {`react`}
    + Celery {`python(flask)`} - Worker for Coffee FE server

- When a new customer is onboarded, a new cluster is assigned and spun up for a customer.
    + The new cluster has:
        * statefulSet -> replicaSet is defined in statefulSet.
        * deployment -> stateless
        * shared secrets -> SSL license + TCP license + .......
        * ... etc.

- `=~` is a bash comparator. It lets the users compare the LHS value by the Regex expression on the RHS.






