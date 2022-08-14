# Write your MySQL query statement below
# nested query
# select name as Customers from Customers  where id NOT IN (select customerId from Orders);\

# correlated subquery
# SELECT A.Name as Customers from Customers A WHERE NOT EXISTS (SELECT 1 FROM Orders B WHERE A.Id = B.CustomerId)

# using join
SELECT A.Name as Customers from Customers A LEFT JOIN Orders B on  A.Id = B.CustomerId WHERE B.CustomerId is NULL
