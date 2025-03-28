select distinct p.product_id
    , ifnull(t.new_price, 10) as price
from Products p
left join (
    select product_id
        , new_price
    from Products
    where (product_id, change_date) in (
        select product_id
            , max(change_date)
        from Products
        where change_date <= '2019-8-16'
        group by product_id
    )
) t on p.product_id = t.product_id