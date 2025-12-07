/* Write your T-SQL query statement below */
Select Case 
            When id % 2 = 1 And Exists (Select 1 id From Seat s2 Where s2.id = s1.id + 1) Then id + 1
            When id % 2 = 0 Then id - 1
            Else id
        End As id, student
From Seat s1
Order By id
