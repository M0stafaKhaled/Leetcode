WITH combined AS (
    SELECT accepter_id AS id
    FROM RequestAccepted
    UNION ALL
    SELECT requester_id AS id
    FROM RequestAccepted
),
counts AS (
    SELECT id, COUNT(*) AS num
    FROM combined
    GROUP BY id
)
SELECT id, num
FROM counts
WHERE num = (SELECT MAX(num) FROM counts);
