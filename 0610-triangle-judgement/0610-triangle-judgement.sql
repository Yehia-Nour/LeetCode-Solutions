/* Write your T-SQL query statement below */
Select 
    x,
    y,
    z,
    Case 
        When x + y > z 
         And x + z > y 
         And y + z > x 
        Then 'Yes'
        Else 'No'
    End As triangle
From Triangle;
