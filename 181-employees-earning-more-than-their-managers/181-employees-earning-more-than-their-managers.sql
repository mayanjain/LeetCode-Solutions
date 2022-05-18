# Write your MySQL query statement below
select a.name as Employee
from employee a,employee b
where a.salary>b.salary and a.managerid=b.id;