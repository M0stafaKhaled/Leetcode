# Write your MySQL query statement below
select d.name  as "Department"    , e.name as Employee  , salary  
from Employee as e 
join Department as d 
on d.id = e.departmentId 
WHERE (
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = e.departmentId
      AND e2.salary > e.salary
) < 3
order by  d.name , e.salary desc 
