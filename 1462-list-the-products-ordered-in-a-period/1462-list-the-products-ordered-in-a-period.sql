# Write your MySQL query statement below
select 
product_name  , sum(unit) as unit
from orders  as o
join products  as  p
on o.product_id   = p.product_id   

where year(order_date) = "2020"
and month(order_date) = 2  
group by product_name
having sum(unit) >=100