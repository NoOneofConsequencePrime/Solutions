select t.employee_id
    , t.name
    , count(a.reports_to) as reports_count
    , round(sum(a.age)/count(a.reports_to)) as average_age
from Employees t
left join Employees a on a.reports_to=t.employee_id
where t.employee_id in (
    select reports_to
    from Employees
)
group by t.employee_id
order by t.employee_id