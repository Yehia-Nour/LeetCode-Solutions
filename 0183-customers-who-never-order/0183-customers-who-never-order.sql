/* Write your T-SQL query statement below */
Select [name] As Customers
From Customers
Where id Not In (Select CustomerId From Orders)