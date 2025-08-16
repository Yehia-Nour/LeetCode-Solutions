/* Write your T-SQL query statement below */
SELECT E.name AS Employee
FROM Employee E INNER JOIN Employee M ON E.managerId = M.id 
WHERE E.salary > M.salary