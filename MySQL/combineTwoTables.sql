CREATE DATABASE person;
use person;

CREATE TABLE Person 
(
    personId INT PRIMARY KEY,
    lastName VARCHAR(30),
    firstName VARCHAR(30)
);

INSERT INTO Person VALUES (1,'Wang','Allen');
INSERT INTO Person VALUES (2,'Alice','Bob');

CREATE TABLE Address 
(
     addressId INT,
     personId INT,
     city VARCHAR(20),
     state VARCHAR(30)
);

INSERT INTO Address VALUES (1,2,'New York City','New York');
INSERT INTO Address VALUES (2,3,'Leetcode','California');


SELECT * FROM Person;
SELECT * FROM Address;

SELECT Person.firstname, Person.lastname,Address.city,Address.state
FROM Person 
LEFT JOIN Address
ON Person.personId = Address.personId;