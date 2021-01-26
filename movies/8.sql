SELECT name FROM people -- name is what we're printing, names only exit in people table.
JOIN stars ON people.id = stars.person_id -- connect the person id from stars table to people id from people table.
JOIN movies ON movies.id = stars.movie_id -- connect the id column from movies table to the foreign key movie_id in stars table.
WHERE title = "Toy Story";