/* Write your T-SQL query statement below */
Select employee_id, department_id
From Employee
Where primary_flag = 'Y'
   Or employee_id In (
        Select employee_id
        From Employee
        Group By employee_id
        Having Count(*) = 1
   )

