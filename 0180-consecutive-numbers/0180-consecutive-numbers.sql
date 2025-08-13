# Write your MySQL query statement below
select distinct  num as ConsecutiveNums 

from Logs as l1 

where 2 = 
(   select  count(num) from logs as l2 
    WHERE (l2.id = l1.id+1 OR l2.id = l1.id+2)
  AND l1.num = l2.num
) 