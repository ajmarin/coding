select
    d.driver_id,
    d.driver_name,
    ROUND(fh_avg, 2) first_half_avg,
    ROUND(sh_avg, 2) second_half_avg,
    ROUND(sh_avg - fh_avg, 2) as efficiency_improvement
from drivers d
join (
    select driver_id,
        avg(case when MONTH(trip_date) <= 6 then distance_km / fuel_consumed end) fh_avg,
        avg(case when MONTH(trip_date) >= 7 then distance_km / fuel_consumed end) sh_avg
    from trips
    group by driver_id
) e using(driver_id)
where sh_avg - fh_avg > 0
order by efficiency_improvement desc, driver_name;
