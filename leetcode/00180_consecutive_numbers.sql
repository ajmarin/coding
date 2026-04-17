select distinct a.Num as ConsecutiveNums
from Logs a
join Logs b on a.id = b.id - 1
join Logs c on b.id = c.id - 1
where a.Num = b.Num and b.Num = c.Num;
