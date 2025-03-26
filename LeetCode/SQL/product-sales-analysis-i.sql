select product_name, year, price
from Sales as s
inner join Product as p on s.product_id = p.product_id