select name from Employee e where id in (
    select managerId from Employee group by managerId having count(1) > 4
)
