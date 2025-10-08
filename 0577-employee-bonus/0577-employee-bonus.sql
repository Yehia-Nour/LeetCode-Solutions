/* Write your T-SQL query statement below */
Select E.name, B.bonus
From Employee E Left Join Bonus B
On E.empId = B.empId
Where B.bonus < 1000 Or B.bonus Is null;