SELECT b.Id
FROM Weather AS a JOIN Weather AS b
ON datediff(b.RecordDate, a.RecordDate) = 1
WHERE b.Temperature > a.Temperature