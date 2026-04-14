select *
from products
where regexp_like(description, '(^| )SN\\d{4}-\\d{4}( |$)', 'c')
order by product_id;
