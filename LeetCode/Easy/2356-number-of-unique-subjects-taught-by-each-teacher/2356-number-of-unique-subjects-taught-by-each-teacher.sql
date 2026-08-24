# Write your MySQL query statement below
SELECT count(DISTINCT subject_id) AS cnt, teacher_id
FROM Teacher
GROUP BY teacher_id;