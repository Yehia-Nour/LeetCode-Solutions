/* Write your T-SQL query statement below */
Select S.Product_id, T.First_year, S.Quantity, S.Price
From Sales S Join (
                Select 
                    Product_id,
                    Min(Year) As First_year
                From Sales
                Group By Product_id
            ) T
        On S.Product_id = T.Product_id
        And S.Year = T.First_year;
