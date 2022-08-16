# Write your MySQL query statement below

# select statement will not work bcoz we need to update in same table itself(we just don't want output)
# select id,name, if(sex='f','m','f') as sex,salary from Salary;

# WORKING QUERIES
# update Salary set sex=if(sex='m','f','m');
update Salary set sex=(
CASE
    WHEN sex='m' THEN 'f'
    ELSE 'm'
END
)
# update Salary set (sex='m' where sex='f') and (sex='f' where sex='m');