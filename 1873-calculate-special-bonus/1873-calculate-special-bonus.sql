# Write your MySQL query statement below

# using if condition
# if(condition, value_if_true, value_if_false) this is the syntax of if in mysql

# NOTE: order by is required bcoz it requires records in ascending order of employee_id (seen in wrong submission)
# SELECT employee_id, IF(employee_id%2=1 AND name NOT LIKE "M%",salary,0) AS bonus from Employees ORDER BY employee_id;


# using case statement
SELECT employee_id, 
CASE 
    WHEN employee_id%2=1 AND name NOT LIKE "M%" THEN salary
    ELSE 0
END
AS bonus from Employees ORDER BY employee_id;

