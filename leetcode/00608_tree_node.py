select id
    , CASE
        WHEN p_id is null THEN "Root"
        WHEN id in (select p_id from Tree) THEN "Inner"
        ELSE "Leaf"
    END as type
FROM Tree;
