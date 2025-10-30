/* Write your T-SQL query statement below */
Select user_id, Count(follower_id) As followers_count
From Followers 
Group By user_id
Order By user_id