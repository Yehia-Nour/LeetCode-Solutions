/* Write your T-SQL query statement below */
Select
    contest_id,
    Round(
        Count(Distinct user_id) * 100.0 / (Select Count(*) From Users),
        2
    ) As percentage
From Register
Group By contest_id
Order By percentage Desc, contest_id Asc;
