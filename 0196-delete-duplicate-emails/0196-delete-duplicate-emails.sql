# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

DELETE FROM Person
WHERE email IN (
    SELECT email
    FROM (
        SELECT email, MIN(id) as keep_id
        FROM Person
        GROUP BY email
        HAVING COUNT(*) > 1
    ) AS duplicates
    WHERE id != keep_id
);