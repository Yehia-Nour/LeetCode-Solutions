/* Write your T-SQL query statement below */
Select  
        date_id, 
        make_name,
        Count(Distinct lead_id) As unique_leads, 
        Count(Distinct partner_id) As unique_partners
From DailySales
Group By date_id, make_name;