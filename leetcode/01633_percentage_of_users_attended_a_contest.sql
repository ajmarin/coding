select contest_id, ROUND(100 * COUNT(c.user_id) / total_users, 2) percentage
from Register c
cross join (select count(1) as total_users from Users) as u
group by contest_id
order by percentage desc, contest_id
