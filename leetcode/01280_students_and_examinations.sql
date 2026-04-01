select stu.student_id, student_name, sub.subject_name, count(e.student_id) as attended_exams
from Students stu
cross join Subjects sub
left join Examinations e
on stu.student_id = e.student_id
and sub.subject_name = e.subject_name
group by student_id, student_name, subject_name
order by student_id, sub.subject_name
