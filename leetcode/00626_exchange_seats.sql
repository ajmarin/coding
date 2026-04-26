select s.id, COALESCE(t.student, s.student) as student
from Seat s
left join Seat t
on s.id - 1 = (t.id - 1) ^ 1;

