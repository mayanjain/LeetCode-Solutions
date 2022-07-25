# Write your MySQL query statement below

select SalesPerson.name from SalesPerson
where sales_id not in (
    select sales_id from Orders 
    where com_id = (
        select com_id 
        from Company 
        where Company.name='RED'
    )
);