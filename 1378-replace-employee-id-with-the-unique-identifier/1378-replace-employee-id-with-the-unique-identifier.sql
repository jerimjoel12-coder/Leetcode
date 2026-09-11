# Write your MySQL query statement below
select empu.unique_id,emp.name from Employees as emp left join EmployeeUNI as empu on emp.id=empu.id;