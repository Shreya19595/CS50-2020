SELECT count(movies.title) from movies
INNER JOIN ratings on movies.id = ratings.movie_id
where ratings.rating = 10.0;