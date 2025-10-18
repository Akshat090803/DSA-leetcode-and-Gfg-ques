-- Write your PostgreSQL query statement below
select
TO_CHAR(trans_date, 'YYYY-MM') as month, country,
count(id) as trans_count,
count(case when state='approved' then 1 else null END ) as approved_count,
sum (amount) as trans_total_amount,
sum (CASE when state ='approved' then amount else 0 END) as approved_total_amount
from transactions
Group by TO_CHAR(trans_date, 'YYYY-MM'), country;
