Select
    m.employee_id,
    m.name,
    Count(e.employee_id) As reports_count,
    Cast(Floor(Avg(Cast(e.age As Float)) + 0.5) As Int) As average_age
From Employees m
Inner Join Employees e
    On m.employee_id = e.reports_to
Group By 
    m.employee_id, 
    m.name
Order By 
    m.employee_id;
