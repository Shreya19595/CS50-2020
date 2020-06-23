SELECT movies.title from stars
INNER JOIN movies ON movies.id = stars.movie_id
INNER JOIN people ON stars.person_id = people.id
INNER JOIN ratings ON ratings.movie_id = stars.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY ratings.rating
LIMIT 5;