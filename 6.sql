SELECT AVG(ratings.rating) from ratings
INNER JOIN movies on ratings.movie_id = movies.id
where movies.year = 2012;