select name as Customers from Customers
left join Orders on Customers.id = customerId
where Orders.id is null
