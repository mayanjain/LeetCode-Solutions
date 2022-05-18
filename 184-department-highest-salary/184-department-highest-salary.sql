# Write your MySQL query statement below
select department.name as Department,a.name as Employee,a.salary as Salary
from employee a
join department
on a.departmentId=department.id
where a.salary=(
    select max(salary) from employee where departmentid=a.departmentid
);