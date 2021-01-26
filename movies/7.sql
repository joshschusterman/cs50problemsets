SELECT title, rating
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title;

-- A little explanation for myself here:
-- SELECT title, rating - this still stays the same because it's what we what to print out, in the column order we want.
-- FROM movies for title, then JOIN ratings... "ON" basically means "CONNECT THIS WAY".
-- So connect by matching the id column in the movies table to the movie_id column in the ratings table...
-- which of course references back to the id column in the movies table. Redundant? Maybe, but that's how it works.