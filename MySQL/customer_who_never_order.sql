-- leetcode 183
CREATE TABLE Customers
(
   id INT PRIMARY KEY,
   cname VARCHAR(20)
);

INSERT INTO customers VALUES(1,'Joe');
INSERT INTO customers VALUES(2,'Henry');
INSERT INTO customers VALUES(3,'Sam');
INSERT INTO customers VALUES(4,'Max');

CREATE TABLE orders
(
    id INT PRIMARY KEY,
    customerid INT,
    CONSTRAINT fk_customer_id FOREIGN KEY (customerid) REFERENCES customers(id)
);

INSERT INTO orders VALUES(1,3);
INSERT INTO orders VALUES(2,1);

SELECT customers.cname AS Customers FROM customers
LEFT JOIN orders ON customers.id = orders.customerid
WHERE orders.customerid IS NULL;



