# Write your MySQL query statement below
SELECT e.name
FROM Employee e
JOIN Employee em
ON e.id = em.managerID
GROUP BY e.id
HAVING COUNT(em.managerID) >=5;