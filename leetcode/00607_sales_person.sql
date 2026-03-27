select name from SalesPerson where sales_id not in
(
    select sales_id from Orders where Orders.com_id in
    (select com_id from Company where Company.name = "RED")
)

