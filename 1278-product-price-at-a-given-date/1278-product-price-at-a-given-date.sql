# Write your MySQL query statement below
select   p1.product_id ,COALESCE(p2.new_price , 10)  as  price 
from Products as p1 
left join products as p2 
on p1.product_id = p2.product_id 
and 
 p2.change_date <= '2019-08-16'
 and 
 p2.change_date =(
    select max(p3.change_date) from products as p3 where p3.product_id = p1.product_id
    and p3.change_date <= '2019-08-16'
 )

group by p1.product_id 
