select ROUND(count(1) / (select count(distinct b.player_id) from Activity b), 2) as fraction
from Activity a
where (a.player_id, date_sub(a.event_date, INTERVAL 1 DAY)) IN (
    select player_id, min(event_date)
    from Activity b
    group by player_id
);
