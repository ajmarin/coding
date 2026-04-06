select user_id, count(1) as followers_count
from Followers
group by user_id
order by user_id
