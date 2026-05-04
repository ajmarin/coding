select ROUND(SUM(tiv_2016), 2) as tiv_2016
from Insurance i1
where i1.tiv_2015 in (select tiv_2015 from Insurance group by tiv_2015 having count(1) > 1)
    and (i1.lat, i1.lon) not in (select lat, lon from Insurance group by lat, lon having count(1) > 1);
