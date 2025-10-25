/* Write your T-SQL query statement below */
Select Round(Sum(Case When order_date = customer_pref_delivery_date Then 1 Else 0 End) * 100.0 / Count(*), 2) As immediate_percentage
From (
    Select customer_id, order_date, customer_pref_delivery_date
    From Delivery d
    Where order_date = (
        Select Min(order_date)
        From Delivery
        Where customer_id = d.customer_id
    )
) As first_orders;