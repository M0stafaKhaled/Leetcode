# Write your MySQL query statement below
select  employee_id  , department_id 
from Employee as e1
where primary_flag  ="Y"  or 
1= (select count(*) from employee as e2 where e2.employee_id = e1.employee_id  )
group by  employee_id  