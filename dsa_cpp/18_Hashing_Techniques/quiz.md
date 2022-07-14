### Question 1:    
Given the following input (4322, 1334, 1471, 9679, 1989, 6171, 6173, 4199) and the hash function x mod 10, which of the following statements are true?

(a) 9679, 1989, 4199 hash to the same value

(b) 1471, 6171 hash to the same value

(c) All elements hash to the same value

(d) Each element hashes to a different value
> ANSWER: 1 and 2 only

### Question 2:    
A hash table contains 10 buckets and uses linear probing to resolve collisions. The key values are integers and the hash function used is key % 10. If the values 43, 165, 62, 123, 142 are inserted in the table, in what location would the key value 142 be inserted?
> ANSWER: 6


### Question 3:    
Consider a hash function that distributes keys uniformly. The hash table size is 20. After hashing of how many keys will the probability that any new key hashed collides with an existing one exceed 0.5.
> ANSWER: 10



### Question 4:    
Consider the hash table of size seven, with starting index zero, and a hash function (3x + 4) mod 7. Assuming the has table is initially empty, which of the following is the contents of the table when the sequence 1, 3, 8, 10 is inserted into the table using closed hashing? Note that -denotes an empty lo 13.17. in the table
> ANSWER: 1,8,10,-,-,-,3

### Question 5:    
Consider a hash table with 9 slots. The hash function is h(k) = k mod 9. The collisions are resolved by chaining. The following 9 keys are inserted in the order: 5, 28, 19, 15, 20, 33, 12, 17, 10. The maximum, minimum, and average chain lengths in the hash table, respectively, are
> ANSWER: 3,0,1


