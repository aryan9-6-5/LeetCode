# Write your MySQL query statement below
SELECT id 
FROM Weather as TOD
WHERE EXISTS( SELECT 1 
    FROM Weather as YES
     WHERE YES.recordDate = DATE_SUB(TOD.recordDate, INTERVAL 1 DAY)
    AND
    TOD.temperature>YES.temperature);
