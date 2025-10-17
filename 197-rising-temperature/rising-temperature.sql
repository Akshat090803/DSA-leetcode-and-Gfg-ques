-- Write your PostgreSQL query statement below

-- select id from weather wO where 
-- temperature > (Select temperature from weather where recordDate = wO.recordDate -1 );

-- Way-2 self join

-- select wL.id from
-- weather wL join weather wR
-- on  wR.id = wL.id - 1
-- where wL.temperature > wR.temperature;

SELECT
    w1.id
FROM
    Weather w1
JOIN
    Weather w2 ON w1.recordDate = w2.recordDate + INTERVAL '1 day'
WHERE
    w1.temperature > w2.temperature;