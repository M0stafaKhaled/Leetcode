SELECT person_name
FROM (
    SELECT 
        person_name,
        SUM(weight) OVER (ORDER BY turn) AS running_weight
    FROM Queue
) q
WHERE running_weight <= 1000
ORDER BY running_weight DESC
LIMIT 1;
