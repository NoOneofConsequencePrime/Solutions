select st.student_id
    , st.student_name
    , sb.subject_name
    , count(e.subject_name) as attended_exams
from Students st
cross join Subjects sb
left join Examinations e on e.student_id = st.student_id
    and e.subject_name = sb.subject_name
group by st.student_id
    , sb.subject_name
order by st.student_id
    , sb.subject_name