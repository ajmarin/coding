select unique_id, name
from Employees e
left join EmployeeUNI eu on e.id = eu.id
