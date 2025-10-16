/* Write your T-SQL query statement below */
Select M.name
From Employee E Inner Join Employee M
On E.managerId = M.id
Group By M.id, M.name
Having Count(M.id) > 4;