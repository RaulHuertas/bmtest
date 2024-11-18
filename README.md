# Beamtrail test

This code is my appication for beamtrail. I used the Qt framework, which can be downloaded from here https://www.qt.io/download-qt-installer-oss?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4. I use Postman to test the API.



# Server

This is the code for the server. Classes 'Movie', 'Seat' and  'Theather' encapsulate the main logic of the application.
Class 'BookingService' adapts the previous clases to the HTTP API.



# Testing

Import the 'Beamtrail.postman_collection.json' into your postman instance. Execute the following requests:
- getMovies: This will return the list of movies currently playing. The position is their index/id for the rest of commands
- getTheaters: This willl return the list of theaters currently playing the movie. The position is their index/id for the rest of commands
- getAvailableSeats: The will return the list of seats currently available for the movie and theater passed as parameters
- bookSeats: This will reserve the seats indicated as url parameters. Will succeed ONLY if all the indicated seats are available. Calling this functions consequtively with different seats will decrease the number of seats available with 'getAvailableSeats'
