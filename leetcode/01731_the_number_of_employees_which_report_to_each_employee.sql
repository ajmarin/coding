select e.employee_id, e.name, count(1) as reports_count, ROUND(SUM(r.age) / COUNT(1), 0) as average_age
from Employees e
join Employees r on e.employee_id = r.reports_to
group by e.employee_id
order by e.employee_id
