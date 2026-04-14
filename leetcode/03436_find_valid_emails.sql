select user_id, email
from Users
where email regexp '^[a-zA-Z0-9_]+@[a-z]+\\.com$'
order by user_id
