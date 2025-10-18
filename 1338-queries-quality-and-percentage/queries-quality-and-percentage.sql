-- Write your PostgreSQL query statement below

select
query_name,
Round(
avg((rating)::numeric/position)
,2) as quality ,
Round(
    -- (sum(Case when rating < 3 then 1 else 0 END)::numeric / count(query_name))*100 
    (count(Case when rating < 3 then 1 else null END)::numeric / count(query_name))*100 
    -- both count and sum will work correct
,2) as poor_query_percentage

from queries
Group By query_name;