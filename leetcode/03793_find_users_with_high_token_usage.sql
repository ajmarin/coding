select p.user_id, count(1) prompt_count, round(avg(tokens), 2) avg_tokens
from prompts p
join (
    select user_id
    from prompts 
    group by user_id
    having count(distinct tokens) > 1
) m
on p.user_id = m.user_id
group by p.user_id
having prompt_count > 2
order by avg_tokens desc, user_id;
