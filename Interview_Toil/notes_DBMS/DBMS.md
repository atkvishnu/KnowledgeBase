---

1. What is DBMS ? Mention advantages.. 

Database Management System (DBMS) is a software for storing and retrieving users’ data while considering appropriate security measures. It consists of a group of programs which manipulate the database. The DBMS accepts the request for data from an application and instructs the operating system to provide the specific data. In large systems, a DBMS helps users and other third-party software to store and retrieve data.

Advantages:

- Improved data sharing
- Improved data security
- Better data integration
- Minimised data inconsistency
- Improved data access
- Improved decision making
- Improved end-user productivity

---

1. What is Database? 

A database is an organised collection of structured information, or data, typically stored electronically in a computer system. A database is usually controlled by a database management system (DBMS). Together, the data and the DBMS, along with the applications that are associated with them, are referred to as a database system, often shortened to just a database.

---

1. What is a database system? 

Together, the data and the DBMS, along with the applications that are associated with them, are referred to as a database system, often shortened to just a database.

---

1. What is RDBMS ? Properties.. 

A Relational Database Management system (RDBMS) is a database management system that is based on the relational model. It has the following major components: Table, Record/Tuple/Row, Field, and Column/Attribute. Examples of the most popular RDBMS are MYSQL, Oracle, IBM DB2, and Microsoft SQL Server database.

Relational databases have the following properties:

- Values are atomic.
- All of the values in a column have the same data type.
- Each row is unique.
- The sequence of columns is insignificant.
- The sequence of rows is insignificant.
- Each column has a unique name.
- Integrity constraints maintain data consistency across multiple tables.

---

1. Types of database languages

- Data Definition Language: DDL stands for Data Definition Language. It is used to define database structure or pattern.
- Data Manipulation Language: DML stands for Data Manipulation Language. It is used for accessing and manipulating data in a database. It handles user requests.
- Data Control Language: DCL stands for Data Control Language. It is used to retrieve the stored or saved data.
- Transaction Control Language: TCL is used to run the changes made by the DML statement. TCL can be grouped into a logical transaction.

---

1. ACID properties (VVVVV IMP) 

To ensure the consistency of the database, certain properties are followed by all the
transactions occurring in the system.
These properties are called ACID Properties of a transaction.

- Atomicity
- Consistency
- Isolation
- Durability

---

1. Difference between vertical and horizontal scaling 

Scaling alters the size of a system. In the scaling process, we either compress or expand the system to meet the expected needs. The scaling operation can be achieved by adding resources to meet the smaller expectation in the current system, or by adding a new system in the existing one, or both.

Vertical scaling keeps your existing infrastructure but adds computing power. Your existing pool of code does not need to change — you simply need to run the same code on machines with better specs. By scaling up, you increase the capacity of a single machine and increase its throughput. Vertical scaling allows data to live on a single node, and scaling spreads the load through CPU and RAM resources for your machines.

Horizontal scaling simply adds more instances of machines without first implementing improvements to existing specifications. By scaling out, you share the processing power and load balancing across multiple machines.

---

1. What is sharding 

Sharding is a method of splitting and storing a single logical dataset in multiple databases. By distributing the data among multiple machines, a cluster of database systems can store larger dataset and handle additional requests. Sharding is necessary if a dataset is too large to be stored in a single database. Moreover, many sharding strategies allow additional machines to be added. Sharding allows a database cluster to scale along with its data and traffic growth.


---

1. Keys in DBMS 

A key is a set of attributes that can identify each tuple uniquely in the given relation.

Types of Keys:

- `Super Key` – A superkey is a set of attributes that can identify each tuple uniquely in the given relation. A super key may consist of any number of attributes.

- `Candidate Key` – A set of minimal attribute(s) that can identify each tuple uniquely in the given relation is called a candidate key.

- `Primary Key` – A primary key is a candidate key that the database designer selects while designing the database. Primary Keys are unique and NOT NULL.

- `Alternate Key` – Candidate keys that are left unimplemented or unused after implementing the primary key are called alternate keys.

- `Foreign Key` – An attribute ‘X’ is called as a foreign key to some other attribute ‘Y’ when its values are dependent on the values of attribute ‘Y’. The relation in which attribute ‘Y’ is present is called the referenced relation. The relation in which attribute ‘X’ is present is called the referencing relation.

- `Composite Key` – A primary key composed of multiple attributes and not just a single attribute is called a composite key.

- `Unique Key` – It is unique for all the records of the table. Once assigned, its value cannot be changed i.e. it is non-updatable. It may have a NULL value.


---

1. Types of relationship 

A relationship is defined as an association among several entities.

- `Unary Relationship Set` – Unary relationship set is a relationship set where only one entity set participates in a relationship set.

- `Binary Relationship Set` – Binary relationship set is a relationship set where two entity sets participate in a relationship set.

- `Ternary Relationship Set` – Ternary relationship set is a relationship set where three entity sets participate in a relationship set.

- `N-ary Relationship Set` – N-ary relationship set is a relationship set where ‘n’ entity sets participate in a relationship set.

---

1. Data abstraction in DBMS, three levels of it 

Data Abstraction is a process of hiding unwanted or irrelevant details from the end user. It provides a different view and helps in achieving data independence which is used to enhance the security of data.

Database systems include complex data-structures. In terms of retrieval of data, reduce complexity in terms of usability of users and in order to make the system efficient, developers use levels of abstraction that hide irrelevant details from the users. Levels of abstraction simplify database design.

---

1. Indexing in DBMS 

Indexing is a way to optimise the performance of a database by minimising the number of disk accesses required when a query is processed. It is a data structure technique which is used to quickly locate and access the data in a database.

---

1. What is DDL (Data Definition Language) 

DDL stands for Data Definition Language. It is used to define database structure or pattern.
It is used to create schema, tables, indexes, constraints, etc. in the database.
Using the DDL statements, you can create the skeleton of the database.
Data definition language is used to store the information of metadata like the number of tables and schemas, their names, indexes, columns in each table, constraints, etc.

---

1. What is DML (Data Manipulation Language)

DML stands for Data Manipulation Language. It is used for accessing and manipulating data in a database. It handles user requests.

---

1. What is normalization ? Types of normalization.

- Normalization is the process of organizing data by disintegrating bigger table into smaller one’s
with proper dependencies

- Redundant Data wastes a lot of disk space and creates maintenance problems (Update, Insert and Delete Anomaly). Hence the DB tables should be Normalized.

- The process of Normalization is achieved by following some rules which are defined as Normal Forms

- There are basically 3 types of Normal Form – 1NF, 2NF, 3NF. Strictness increases as we go from 1NF to 3NF.

- Apart from the above mentioned Normal Form there exist one more Form called Boyce Codd Normal Form (BCNF) . This is an advanced version of 3NF and is even stricter than 3NF.

---

1. What is denormalization ? 

Denormalization is a database optimization technique in which we add redundant data to one or more tables. This can help us avoid costly joins in a relational database. Note that denormalization does not mean not doing normalisation. It is an optimization technique that is applied after doing normalisation.

---

1. What is functional dependency ? 

A functional dependency is a constraint that specifies the relationship between two sets of attributes where one set can accurately determine the value of other sets. It is denoted as X → Y, where X is a set of attributes that is capable of determining the value of Y. The attribute set on the left side of the arrow, X is called Determinant, while on the right side, Y is called the Dependent.

---

1. E-R Model ? 

ER model stands for an Entity-Relationship model. It is a high-level data model. This model is used to define the data elements and relationship for a specified system.

It develops a conceptual design for the database. It also develops a very simple and easy to design view of data.
In ER modelling, the database structure is portrayed as a diagram called an entity-relationship diagram.

---

1.  Conflict Serializability in DBMS .. 

Serializability is a concept that helps us to check which schedules are serializable. A serializable schedule is the one that always leaves the database in consistent state.

A schedule is called conflict serializability if after swapping of non-conflicting operations, it can transform into a serial schedule. The schedule will be a conflict serializable if it is conflict equivalent to a serial schedule.

---

1. What is CCP ? (Concurrency Control Protocols) 

Concurrency Control is the management procedure that is required for controlling concurrent execution of the operations that take place on a database.

The concurrency control protocols ensure the atomicity, consistency, isolation, durability and serializability of the concurrent execution of the database transactions.

Therefore, these protocols are categorised as:

- Lock Based Concurrency Control Protocol
- Timestamp Concurrency Control Protocol
- Validation Based Concurrency Control Protocol

---

1. Entity, Entity Type, Entity Set, Weak Entity Set.. 

Entity in DBMS can be a real-world object with an existence, For example, in a College database, the entities can be Professor, Students, Courses, etc.

The entity type is a collection of the entity having similar attributes.

Types of Entity type:

- `Strong Entity Type`: Strong entities are those entity types which have a key attribute. The primary key helps in identifying each entity uniquely. It is represented by a rectangle.

- `Weak Entity Type`: Weak entity type doesn’t have a key attribute. Weak entity types can’t be identified on their own. It depends upon some other strong entity for its distinct identity.

- `Entity Set`: Entity Set is a collection of entities of the same entity type. We can say that entity type is a superset of the entity set as all the entities are included in the entity type.

---

1. What are SQL commands ? Types of them.. 

[SQL commands](https://www.javatpoint.com/dbms-sql-command)

---

1. Nested Queries in SQL ? 

[Nested Queries](https://www.tutorialspoint.com/explain-about-nested-queries-in-dbms)

---

1. What is JOIN .. Explain types of JOINs 

[join](https://www.javatpoint.com/dbms-sql-joins)

---

1. Inner and Outer Join 

Here are the different types of the JOINs in SQL:

- `(INNER) JOIN`: Returns records that have matching values in both tables
- `LEFT (OUTER) JOIN`: Returns all records from the left table, and the matched records from the right table
- `RIGHT (OUTER) JOIN`: Returns all records from the right table, and the matched records from the left table
- `FULL (OUTER) JOIN`: Returns all records when there is a match in either left or right table

---

1. Diff between 2 tier and 3 tier architecture 

[2 tier and 3 tier architecture](https://www.geeksforgeeks.org/difference-between-two-tier-and-three-tier-database-architecture/)

---

1. Diff between TRUNCATE and DELETE command .. 

---

1. Difference between Intension and Extension in a DataBase

---

1. Difference between share lock and exclusive lock, definition of lock 

---
