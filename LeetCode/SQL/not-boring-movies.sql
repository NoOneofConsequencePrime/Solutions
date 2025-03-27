select id, movie, description, rating
from Cinema
where id%2 = 1
    and (
        description <> 'boring'
        or description is null
    )
order by rating desc