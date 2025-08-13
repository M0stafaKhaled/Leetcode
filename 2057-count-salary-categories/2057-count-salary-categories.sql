# Write your MySQL query statement below
select   r.salary_level as category  , count(a.income) as accounts_count   
from Accounts as a
right join 
(
SELECT 'Low Salary'   AS salary_level
UNION ALL
SELECT 'Average Salary' AS salary_level
UNION ALL
SELECT 'High Salary' AS salary_level
 
) as r
on  (a.income <20000 and r.salary_level = 'Low Salary')
or ( a.income >=20000 and a.income <=50000  and r.salary_level = 'Average Salary')
or (a.income>50000 and   r.salary_level = 'High Salary' )  

group by r.salary_level

--  (
--     case 
--     when income  <20000  then "Low Salary"
--     when income >=20000 and income <=50000 then "Average Salary"
--     when income >50000 then "High Salary"
--     end 
-- )  as category , 