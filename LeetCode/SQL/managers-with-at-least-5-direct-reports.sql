select name
from Employee a
inner join (
    select managerId, count(managerId) as reports
    from Employee
    group by managerId
    having count(*) >= 5
) b on a.id = b.managerId