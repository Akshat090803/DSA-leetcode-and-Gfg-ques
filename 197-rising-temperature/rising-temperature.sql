-- Write your PostgreSQL query statement below

select id from weather wO where 
temperature > (Select temperature from weather where recordDate = wO.recordDate -1 );