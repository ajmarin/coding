select id,
    SUM(IF(month = "Jan", revenue, null)) as Jan_Revenue,
    SUM(IF(month = "Feb", revenue, null)) as Feb_Revenue,
    SUM(IF(month = "Mar", revenue, null)) as Mar_Revenue,
    SUM(IF(month = "Apr", revenue, null)) as Apr_Revenue,
    SUM(IF(month = "May", revenue, null)) as May_Revenue,
    SUM(IF(month = "Jun", revenue, null)) as Jun_Revenue,
    SUM(IF(month = "Jul", revenue, null)) as Jul_Revenue,
    SUM(IF(month = "Aug", revenue, null)) as Aug_Revenue,
    SUM(IF(month = "Sep", revenue, null)) as Sep_Revenue,
    SUM(IF(month = "Oct", revenue, null)) as Oct_Revenue,
    SUM(IF(month = "Nov", revenue, null)) as Nov_Revenue,
    SUM(IF(month = "Dec", revenue, null)) as Dec_Revenue
from Department
group by id;
