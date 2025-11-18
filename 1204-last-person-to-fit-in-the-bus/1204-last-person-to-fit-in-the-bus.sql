/* Write your T-SQL query statement below */
WITH Cumulative AS (
    SELECT 
        person_name,
        turn,
        weight,
        SUM(weight) OVER (ORDER BY turn ROWS UNBOUNDED PRECEDING) AS total_weight
    FROM Queue
)
SELECT TOP 1 person_name
FROM Cumulative
WHERE total_weight <= 1000
ORDER BY turn DESC;
