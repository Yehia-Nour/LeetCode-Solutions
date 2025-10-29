/* Write your T-SQL query statement below */
Select class
From Courses 
Group By class
Having Count(student) >= 5