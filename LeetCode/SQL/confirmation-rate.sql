select s.user_id
    , if(c.rate is not null, c.rate, 0) as confirmation_rate
from Signups s
left join (
    select user_id
        , round(avg(if(action = 'confirmed', 1, 0)), 2) as rate
    from Confirmations
    group by user_id
) c on c.user_id = s.user_id