# Write your MySQL query statement below
select name from Customer where id NOT IN (select id from Customer where referee_id=2);