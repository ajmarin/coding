select max(num) as num from (
    select num from MyNumbers
    group by num
    having count(1) = 1
) as foo
