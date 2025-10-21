/* Write your T-SQL query statement below */
Select p.project_id, CAST(SUM(e.experience_years) * 1.0 / COUNT(p.employee_id) AS DECIMAL(18,2)) AS [average_years]
From Project p Inner Join Employee e
On p.employee_id = e.employee_id
Group By p.project_id