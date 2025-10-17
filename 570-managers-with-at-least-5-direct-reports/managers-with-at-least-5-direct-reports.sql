

-- run this to understsmnd the joined table
-- select
-- e1.name,e2.name,e2.managerId from
-- employee e1 join employee e2
-- on e1.id = e2.managerId;


select
e1.name from
employee e1 join employee e2
on e1.id = e2.managerId
group by e1.name,e1.id 
having count(e1.id)>=5;