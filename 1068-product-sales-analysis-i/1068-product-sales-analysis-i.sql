/* Write your T-SQL query statement below */
Select P.product_name, S.year, S.price
From Sales S Inner Join Product P
On S.product_id = P.product_id