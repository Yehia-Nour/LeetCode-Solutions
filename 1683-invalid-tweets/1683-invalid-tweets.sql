/* Write your T-SQL query statement below */
SELECT tweet_id
FROM Tweets 
WHERE LEN(content) > 15;