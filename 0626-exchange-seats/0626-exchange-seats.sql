WITH seat_count AS (
    SELECT COUNT(*) AS p
    FROM Seat
)
SELECT 
    s.id,
    CASE 
        WHEN s.id % 2 = 1 AND s.id <> sc.p 
            THEN (SELECT student FROM Seat s2 WHERE s2.id = s.id + 1)
        WHEN s.id % 2 = 0 
            THEN (SELECT student FROM Seat s2 WHERE s2.id = s.id - 1)
        ELSE s.student
    END AS student
FROM Seat s
JOIN seat_count sc ON 1=1
ORDER BY s.id;
