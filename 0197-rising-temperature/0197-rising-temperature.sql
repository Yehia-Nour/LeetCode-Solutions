/* Write your T-SQL query statement below */
Select w1.id As Id
From Weather w1 Inner Join Weather w2
On DATEDIFF(day, w2.recordDate, w1.recordDate) = 1
Where w1.temperature > w2.temperature;
