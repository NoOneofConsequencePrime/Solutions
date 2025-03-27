select r.contest_id
    , round(count(u.user_id)/(select count(*) from Users)*100, 2) as percentage
from Register r
inner join Users u on u.user_id = r.user_id
group by r.contest_id
order by percentage desc, contest_id asc