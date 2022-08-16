# Write your MySQL query statement below

# select statement will not work bcoz we need to update in same table itself(we just don't want output)
# select id,name, if(sex='f','m','f') as sex,salary from Salary;

# WORKING QUERIES
# 1)
# update Salary set sex=if(sex='m','f','m');

# 2)
# update Salary set sex=(
# CASE
#     WHEN sex='m' THEN 'f'
#     ELSE 'm'
# END
# )

# 3)
UPDATE salary SET sex = REPLACE ('fm', sex, '');