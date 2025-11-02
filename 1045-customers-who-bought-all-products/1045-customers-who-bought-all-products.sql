/* Write your T-SQL query statement below */
Select customer_id
From Customer
Group by customer_id
Having Count(Distinct product_key) = (Select Count(Distinct product_key) From Product)
