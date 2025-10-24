/* Write your T-SQL query statement below */
Select 
    Format(trans_date, 'yyyy-MM') As month,
    country,
    Count(*) As trans_count,
    Count(Case When [state] = 'approved' Then 1 Else Null End) As approved_count, 
    Sum(amount) As trans_total_amount, 
    Sum(Case When [state] = 'approved' Then amount Else 0 End) As approved_total_amount
From 
    Transactions 
Group By 
    Format(trans_date, 'yyyy-MM'), 
    country;