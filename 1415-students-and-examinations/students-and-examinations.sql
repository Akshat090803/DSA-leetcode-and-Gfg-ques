-- Write your PostgreSQL query statement below
SELECT 
    st.student_id, 
    st.student_name, 
    su.subject_name,
    count(ex.subject_name) as attended_exams
    
FROM 
    students st
  
cross JOIN subjects su 
LEFT JOIN Examinations ex
    ON st.student_id = ex.student_id
    AND su.subject_name = ex.subject_name
GROUP BY
    st.student_id, st.student_name, su.subject_name
order by
  student_id asc , subject_name asc;
