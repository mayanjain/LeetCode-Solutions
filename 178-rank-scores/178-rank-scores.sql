# Write your MySQL query statement below
select score,(select count(distinct score) from scores where score>a.score)+1 as 'rank'
from scores a
order by score desc;