-- Write your PostgreSQL query statement below

select 
p.project_id, round (avg (e.experience_years)::numeric,2) as average_years  from
employee e join project p
on e.employee_id = p.employee_id
group by
p.project_id;

