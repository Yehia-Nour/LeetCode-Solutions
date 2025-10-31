/* Write your T-SQL query statement below */
Select Max(num) As num
From MyNumbers
Where num In (
    Select num
    From MyNumbers
    Group By num
    Having Count(*) = 1
);
