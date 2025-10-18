-- Write your PostgreSQL query statement below

-- select 
-- s.user_id , round( AVG(IF (c.action='confirmed',1,0)) ,2) as confirmation_rate from
-- signups s left join confirmations c
-- on s.user_id = c.user_id
-- group by s.user_id;

SELECT
    s.user_id,
    round(AVG(CASE when c.action='confirmed' then 1 else 0 End), 2 )AS confirmation_rate
FROM
    Signups s
LEFT JOIN
    Confirmations c ON s.user_id = c.user_id
GROUP BY
    s.user_id;
