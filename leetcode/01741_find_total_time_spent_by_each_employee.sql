select event_day as day, emp_id, SUM(out_time) - SUM(in_time) total_time
from Employees
group by emp_id, event_day
