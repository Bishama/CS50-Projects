-- Keep a log of any SQL queries you execute as you solve the mystery.

--Time of theft : 10:15 am
--earliest flight from fiftyville on 29 July.
SELECT * FROM airports
8 | CSF | Fiftyville Regional Airport | Fiftyville
SELECT * FROM flights WHERE origin_airport_id=8 AND year=2020 AND month=7 AND day=29;
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
-- Answer is London

--thief left parking around 10:25 am within 10 minutes of theft. ATM fifer street withdraw money.
SELECT license_plate FROM courthouse_security_logs WHERE year=2020 AND month=7 AND day=28 AND activity='exit' AND hour=10 AND minute<26;
id | year | month | day | hour | minute | activity | license_plate
260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55
268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58
SELECT account_number FROM atm_transactions WHERE year=2020 AND day=28 AND transaction_type='withdraw' AND month=7 AND atm_location='Fifer Street';
id | account_number | year | month | day | atm_location | transaction_type | amount
246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35

--Call made by thief > 1min
SELECT caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration<=60;
id | caller | receiver | year | month | day | duration
221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
234 | (609) 555-5876 | (389) 555-5198 | 2020 | 7 | 28 | 60
251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54

--Suspect list 5
SELECT * FROM people WHERE license_plate IN
FROM courthouse_security_logs WHERE year=2020 AND month=7 AND day=28 AND activity='exit' AND hour=10)
AND phone_number IN
(SELECT caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration<=60);
id | name | phone_number | passport_number | license_plate
398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X

--Thief Ernest
SELECT * FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id

WHERE bank_accounts.account_number IN
(SELECT account_number FROM atm_transactions WHERE year=2020 AND day=28 AND transaction_type='withdraw' AND month=7 AND atm_location='Fifer Street')

AND license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year=2020 AND month=7 AND day=28 AND activity='exit' AND hour=10 AND minute<26)

AND phone_number IN
(SELECT caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration<=60)

AND passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE
origin_airport_id=8 AND year=2020 AND month=7 AND day=29 AND destination_airport_id = 4
AND hour=8 AND minute=20));
id | name | phone_number | passport_number | license_plate | account_number | person_id | creation_year
686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X | 49610011 | 686048 | 2010


-- Accomplice Berthold
SELECT * FROM people
JOIN phone_calls ON phone_calls.receiver=people.phone_number
WHERE phone_calls.year=2020 AND phone_calls.month=7 AND phone_calls.day=28 AND phone_calls.duration<=60
AND phone_calls.caller IN
(SELECT phone_number FROM people WHERE name = 'Ernest');
id | name | phone_number | passport_number | license_plate | id | caller | receiver | year | month | day | duration
864400 | Berthold | (375) 555-8161 |  | 4V16VO0 | 233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45




