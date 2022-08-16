# Write your MySQL query statement below
# 1-based indexing in substr function in sql
select user_id, concat(upper(substr(name,1,1)),lower(substr(name,2))) as name from Users order by user_id;