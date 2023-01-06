# issue/search-filtering

- Hey, so i have a small bugfix for a customer issue i want you to work on
- We will discuss tonight. We made one change but had to revert it as it wasnt complete. Its a good item to pick up on as a first small project while you work on design for the rename rule.

- So if you remember we discussed a fix for search filtering where a user searches by key/value. e.g. status_code == 500.

- no this is for search, its a different workflow, this is when you search for logs like elastic or splunk.

- so what we do today is we take status_code and 500
- and make then into hash's and lookup our index
- then do an and to narrow down the search space
- so lets say status_code return 100 objects and 500 returns 5 objects
- we can then search the intersection to find the data faster
- the challenge with this is sometimes the value is unique enough that we dont need the first lookup
- so if somene says lookup name == vishnu
- name is common and will appear in every line
- vishnu is rare
- and so we can decide that its ok to search just by vishnu
- but if user says status_code == 500
- searching just by 500 will be bad as it will match a lot of integers
- so we need a heuristic where we decide based on both value and keyword
- what we will do is if we detect user is asking for value which is alphanumeric, we can robably just ignore the key
- vs if user is using just integer lookup which usually has lots of collisions
- we can make this more robust by defining a  uniqueness factor for every value call it uniquef(value)
- it can look at things like is it alphanumeric, how long is the value etc.
- if uniqueness factor is high we just use the value
- e.g. name =~ abh
- the uniqueness factor abh is not very high
- but name =~ abhay is high as its alonger string
- so if we define a uniqeness factor function we can determing should we issue both key and value for lookups


- but something to think about meanwhile - what would be a good approach for this uniqueness e.g. if value is a uuid - it is globaly unique, so its a very high uniquness factor

- yes. uniqueness factor will depend upon the distinction between integer and alphanumeric strings and will also depend upon the size of the string.(edited)


- We will still be making hash and looking it up based on `uniquef(value)` function's output.
- If uniqueness factor is high we will use the `value` only lookup, else we will be using both `key/value` lookup!
- Is this a correct understanding of the problem?


- yes
- We already do the hash
- right now we use all so in above example all 4 status_code event 500 and filter_session_tokene_e000e will be hashed then we lookup metadata for each
- and then intersect
- since filter_session_token_e000e is quite unique using event is unnecessary
- saving us wasted lookup for event
- it would perform better if we just intersected 3 vs 4


- Ok so we are looking up values for 4 data points, we can save up on this with the uniquef method.
- In some cases, we will only have to lookup 1 data point, in other cases it will be all 4 data points.


- `Yes so the final intersection list should be based on uniqueness factor`
- calculated based on value
- `If uniqueness factor is higher than a threshold exclude key, If it’s lower than threshold include key as well`










### github

- so we have release and rc
- and customer/<customer-name>-release
- in this case you fork from the customer release branch and do pr to that
- and rc
- we will eventually do a pr for rc to release