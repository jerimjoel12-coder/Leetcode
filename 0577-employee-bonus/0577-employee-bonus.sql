# Write your MySQL query statement below
select emp.name,bon.bonus from Employee as emp left join Bonus as bon on emp.empId=bon.empId where bon.bonus is null or bon.bonus<1000;