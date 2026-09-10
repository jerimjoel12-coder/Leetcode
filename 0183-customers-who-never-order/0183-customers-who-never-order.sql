# Write your MySQL query statement below
select name as Customers from Customers as cus left join Orders as ord on cus.id=ord.customerId where ord.customerId is null;