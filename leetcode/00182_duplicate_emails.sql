select email
from Person
group by email
having count(1) > 1
