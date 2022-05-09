
/* 6. We have phone numberm(caller id) of the accomplice
     id | caller | receiver | year | month | day | duration
     255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
*/
SELECT * FROM phone_calls WHERE duration < 60 AND month = 7 AND day = 28;



/* 7. Origin ,destination and flight id of earlies flight
   id | origin_airport_id | destination_airport_id | hour | minute
   27 |                5 |                      8 |    8 | 35
*/
SELECT id, origin_airport_id, destination_airport_id, hour, minute FROM flights WHERE month = 7 AND day = 28;


/* 8. From flight id we have passport number and seat of passengers
flight_id | passport_number | seat
27 | 4631067354 | 5C
27 | 9698118788 | 6B
27 | 9355133130 | 7D
27 | 1207566299 | 8C
27 | 6131360461 | 9A
27 | 4223654265 | 2C
27 | 7712200330 | 3C
*/
SELECT * FROM passengers WHERE flight_id = 27;



SELECT full_name, people.passport_number, people.name FROM airports
    JOIN flights ON flights.destination_airport_id = airports.id
    JOIN passengers ON passengers.flight_id = flights.id
    JOIN people ON people.passport_number = passengers.passport_number
    WHERE people.name = 'Russell' AND flights.hour = 8 AND flights.minute = 35;