/*SELECT movies.id, movie_id, people.id, person_id, name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE name = 'Kevin Bacon' AND birth = 1958;*/

SELECT name FROM people
WHERE id IN
(SELECT person_id FROM stars WHERE movie_id IN(SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name ='Kevin Bacon' AND birth = '1958')))
AND 
name != 'Kevin Bacon';

/*CREATE TABLE movies (
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
            );
CREATE TABLE people (
                id INTEGER,
                name TEXT NOT NULL,
                birth NUMERIC,
                PRIMARY KEY(id)
            ); */