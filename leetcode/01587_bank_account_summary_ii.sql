select name, sum(amount) as balance
from Users u
join Transactions t on u.account = t.account
group by 1
having balance > 10000
