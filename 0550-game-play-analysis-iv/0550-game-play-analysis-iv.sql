Select 
    Round(
        Count(Distinct a.player_id) * 1.0 / Count(Distinct b.player_id),
        2
    ) As fraction
From Activity a
Right Join (
    Select 
        player_id, 
        Min(event_date) As first_login
    From Activity
    Group By player_id
) b
On a.player_id = b.player_id
And a.event_date = DATEADD(DAY, 1, b.first_login);