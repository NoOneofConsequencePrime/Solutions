select customer_id, count(visit_id) as count_no_trans
from Visits as v
where v.visit_id not in (
    select t.visit_id
    from Transactions as t
)
group by customer_id