select query_name,
    ROUND(AVG(rating / position), 2) as quality,
    ROUND(AVG(IF(rating < 3, 100, 0)), 2) as poor_query_percentage
from Queries
group by query_name
