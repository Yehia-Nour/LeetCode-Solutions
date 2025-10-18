/* Write your T-SQL query statement below */
Select id, movie, [description], rating
From Cinema
Where [description] != 'boring' And id % 2 != 0
Order By rating desc