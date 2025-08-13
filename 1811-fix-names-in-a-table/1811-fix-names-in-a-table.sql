# Write your MySQL query statement below


select user_id , CONCAT(UPPER(left(name ,1)) , lower(SUBSTRING(name , 2   )) ) As name from Users ORDER BY user_id