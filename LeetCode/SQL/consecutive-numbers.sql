select distinct t1.num as ConsecutiveNums
from Logs t1, Logs t2, Logs t3
where t1.num = t2.num and t2.num = t3.num
    and t1.id+1 = t2.id and t2.id+1 = t3.id