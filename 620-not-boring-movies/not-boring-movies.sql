-- Write your PostgreSQL query statement below
select 
   * from cinema 
where
   id % 2 = 1 and not description = 'boring'
Order By
    rating desc;
  
