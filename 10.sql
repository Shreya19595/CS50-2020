SELECT distinct people.name from directors
INNER JOIN people ON directors.person_id = people.id
INNER JOIN ratings ON ratings.movie_id = directors.movie_id
where ratings.rating >= 9.0;