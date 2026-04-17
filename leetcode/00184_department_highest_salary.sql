select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e
join Department d on e.departmentId = d.id
join (
    select max(salary) as maxSalary, departmentId
    from Employee
    group by departmentId
) maxsal on e.departmentId = maxsal.departmentId and e.salary = maxSalary

