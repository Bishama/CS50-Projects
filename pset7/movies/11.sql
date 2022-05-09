SELECT title FROM movies 
JOIN ratings ON ratings.movie_id = movies.id
WHERE id IN 
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman'))
ORDER BY ratings.rating DESC LIMIT 5


/* CREATE TABLE movies (                                                                                
                    id INTEGER,
                    title TEXT NOT NULL,
                    year NUMERIC,
                    PRIMARY KEY(id)
                );
CREATE TABLE stars (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)

CREATE TABLE ratings (
                movie_id INTEGER NOT NULL,
                rating REAL NOT NULL,
                votes INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id)
            );
            CREATE TABLE people (
                id INTEGER,
                name TEXT NOT NULL,
                birth NUMERIC,
                PRIMARY KEY(id)
            ); */
