select class
from Courses
group by class
having count(1) > 4;
