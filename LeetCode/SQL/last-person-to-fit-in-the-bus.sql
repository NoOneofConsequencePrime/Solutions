select person_name
from Queue
where (turn) in (
    select max(turn)
    from Queue
    where (person_id) in (
        select a.person_id
        from Queue a, Queue b
        group by a.person_id
        having sum(
                if(a.turn >= b.turn, b.weight, 0)
            ) <= 1000
    )
)