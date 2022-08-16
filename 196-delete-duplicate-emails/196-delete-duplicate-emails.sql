# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete from Person where id not in(select min(id) as id from (select * from Person) as something group by email);