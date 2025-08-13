# Write your MySQL query statement below
with names as (
    select  name , count(*) as r
from users  as u
join MovieRating as m 
where u.user_id = m.user_id 
group by u.user_id 
ORDER BY r DESC ,  name ASC
limit 1 
),
 mov as 
(
    select mo.title   ,avg(rating) as r
from MovieRating as m 
join Movies as mo 
on mo.movie_id      = m.movie_id      
WHERE YEAR(created_at) = 2020
  AND MONTH(created_at) = 2
group by  mo.title     
order by r desc , mo.title asc
limit 1 
)
SELECT trim(name) AS results FROM names
UNION All
SELECT trim(title) AS results FROM mov




 