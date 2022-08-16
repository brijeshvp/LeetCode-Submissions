# Write your MySQL query statement below

# if(condition, value_if_true, value_if_false) this is the syntax of if in mysql
SELECT employee_id, IF(employee_id%2=1 AND name NOT LIKE "M%",salary,0) AS bonus from Employees ORDER BY employee_id;
