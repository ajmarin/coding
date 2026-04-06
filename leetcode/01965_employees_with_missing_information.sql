select employee_id from (
    select *
    from Employees
    left join Salaries USING(employee_id)
    union
    select *
    from Salaries
    left join Employees USING(employee_id)
) temp
where temp.salary is null or temp.name is null
order by employee_id;
