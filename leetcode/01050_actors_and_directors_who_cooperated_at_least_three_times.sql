select actor_id, director_id
from ActorDirector
group by 1, 2
having count(1) > 2;
