select customer_id, count(visit_id) as count_no_trans
from Visits as v
where not exists(
    select t.visit_id
    from Transactions as t
    where t.visit_id = v.visit_id
)
group by customer_id