# Write your MySQL query statement below

select   ROUND(

(select  count(*)
from Delivery as d1
where customer_pref_delivery_date = order_date
and order_date   = (select min(d2.order_date) from  Delivery as d2 where d1.customer_id = d2.customer_id)
) / count(distinct customer_id) *100
,2

)  as immediate_percentage  
from Delivery


-- select count(distinct customer_id) / ()
-- from Delivery

