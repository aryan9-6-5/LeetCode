# Write your MySQL query statement below
SELECT 
    d.name as Department,
    e1.name as Employee,
    e1.salary as Salary
FROM Employee as e1
JOIN Department d
on e1.departmentID=d.id
WHERE (
    SELECT COUNT(DISTINCT e2.salary)
    from Employee e2
    WHERE e2.departmentID=e1.departmentID
    AND e2.salary>e1.salary
)<3;