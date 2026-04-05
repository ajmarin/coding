select machine_id,
    ROUND(
        2 * (
            SUM(IF(activity_type = "end", timestamp, 0))
            - SUM(IF(activity_type = "start", timestamp, 0))
        ) / COUNT(1),
        3
    ) as processing_time
from Activity
group by machine_id
