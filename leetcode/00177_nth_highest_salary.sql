CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    select salary
    from (
        select row_number() over (order by salary desc) as rn, salary
        from Employee
        group by salary
    ) with_num where rn = N
  );
END
