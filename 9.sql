SELECT DISTINCT people.name from stars
INNER JOIN people ON stars.person_id = people.id
INNER JOIN movies ON movies.id = stars.movie_id
where movies.year = 2004
ORDER BY people.birth;