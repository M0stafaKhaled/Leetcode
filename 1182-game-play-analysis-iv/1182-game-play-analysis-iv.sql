# Write your MySQL query statement below

select round (

    (select 
count(distinct player_id)
from Activity as a 
where event_date =  (select  DATE_ADD(min(a2.event_date ), INTERVAL 1 DAY) 
from  Activity as a2 where a.player_id = a2.player_id 
)

)
/count(distinct player_id) , 2
) as fraction 
from Activity