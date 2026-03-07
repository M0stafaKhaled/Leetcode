# Write your MySQL query statement below
--  DATE_ADD('2024-03-10', INTERVAL 1 DAY)


 select b.id as Id  from  Weather as a 

join Weather as b 
 on  a.recordDate  =  DATE_SUB(b.recordDate, INTERVAL 1 DAY)
 where  a.temperature  < b.temperature 
