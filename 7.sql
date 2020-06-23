SELECT movies.title, ratings.rating
from ratings
INNER JOIN movies on ratings.movie_id = movies.id
where movies.year = 2010 AND ratings.rating != "\N"
ORDER BY ratings.rating DESC, movies.title;