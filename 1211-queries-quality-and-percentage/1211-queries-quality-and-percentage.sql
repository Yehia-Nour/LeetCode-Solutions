/* Write your T-SQL query statement below */
Select 
    Query_Name,
    Round(Avg(Rating * 1.0 / Position), 2) As Quality,
    Round(Sum(Case When Rating < 3 Then 1 Else 0 End) * 100.0 / Count(*), 2) As Poor_Query_Percentage
From 
    Queries
Group By 
    Query_Name;
