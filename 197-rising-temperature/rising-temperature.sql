-- Write your PostgreSQL query statement below

-- select id from weather wO where 
-- temperature > (Select temperature from weather where recordDate = wO.recordDate -1 );

-- Way-2 self join

-- select wL.id from
-- weather wL join weather wR
-- on  wR.id = wL.id - 1
-- where wL.temperature > wR.temperature;

SELECT
    today.id
FROM
    Weather today
JOIN
    Weather yesterday ON today.recordDate = yesterday.recordDate + INTERVAL '1 day'
WHERE
    today.temperature > yesterday.temperature;