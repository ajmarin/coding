select product_name, sum(unit) as unit
from Orders o
join Products p on o.product_id = p.product_id
where order_date between "2020-02-01" and "2020-02-29"
group by o.product_id
having unit > 99
