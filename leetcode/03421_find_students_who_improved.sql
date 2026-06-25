select student_id, subject, first_score, latest_score
from (
    select  student_id, 
            subject,
            first_value(score) over (partition by student_id, subject order by exam_date) as first_score,
            first_value(score) over (partition by student_id, subject order by exam_date desc) as latest_score
    from scores
) ranked
group by student_id, subject
having latest_score > first_score
order by student_id, subject;
