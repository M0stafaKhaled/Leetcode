# Write your MySQL query statement below
select  DATE_FORMAT(trans_date, '%Y-%m')  as month         , country , 

count(id) as trans_count  ,
(select count(state) from Transactions as t2 where state = "approved"
 and  coalesce(t1.country , 0) = coalesce(t2.country , 0)  and month =  DATE_FORMAT(t2.trans_date, '%Y-%m')
) as approved_count 
,
sum(amount) as trans_total_amount  , 

(select coalesce(sum(amount) , 0) from Transactions  as t2 where t2.state = "approved" 
 and  coalesce(t1.country , 0) = coalesce(t2.country , 0)  and month =  DATE_FORMAT(t2.trans_date, '%Y-%m')
 )
as approved_total_amount 

from  Transactions as t1
   group by   month ,country 