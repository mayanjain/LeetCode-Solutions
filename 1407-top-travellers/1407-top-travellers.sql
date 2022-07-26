# Write your MySQL query statement below
select name, ifnull(sum(distance),0) as travelled_distance 
from Users
left join Rides
on users.id=user_id
group by users.id
order by travelled_distance desc,name;