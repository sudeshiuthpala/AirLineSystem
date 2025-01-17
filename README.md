# AirLineSystem
 c++
Problem 
 
A small airline company (Virgin Airline) needs a program to carry out seat reservation for 
its flights. You are to write a demonstration seat reservation program for this company. 
 
Description of Class and its functionality 
 
 
The program is to be menu driven with the following options: 
 
 
1 Display available flights 
 2 View flight 
 3 Seat availability 
 4 Seat booking 
 5Exit 
 
 
 
 
Option One (1) 
 The program should list all flight numbers that have at least one seat available. The screen display should show the flight number, departure date and time, departure airport code, arrival airport code and the number of seats available with their class. 
 
Option two (2) 
 The program should prompt the user for a flight number. The program should then search the 
database for the requested flight. An appropriate error message should appear if the flight is 
not present. If the flight is found the display should show all available seat numbers together with their class, the total number of available seats in each class, the departure and arrival airports, the departure date and time. 
 
Option three (3) 
 The program should prompt the user for a flight number. It should then request the number of 
seats required by the customer. The program will then need to search the flight to see if that 
number of seats is available. If they are then a message giving the seat numbers available 
should appear on screen. If not an appropriate error message should be given. 
 
Option four (4) 
 The program should prompt for a flight number and seat location in order to make a booking. Seats are numbered by rows 1..60 and A..F in each row. If the seat is available it should be allocated and therefore should not show as available any more. If a non-available seat is requested an error message should appear. 
 
Option four (5) 
 Upon exit the modified data should be written to the same file (called flights.dat) in the same format as originally. 
 
 
 
 
Data Structures 
 You are to use an object-oriented approach to this problem. There should be a flight class where all flights being contained in an array of records (structs) in the flight class. Within each flight there should be an array of char representing the seats. 
 
 
A file of data called flights.txt will be provided which your program must read in to 
begin. The data will be the flight numbers, departure dates/times, airports and 
seating. Your program will be tested on a similar file of data. DO NOT create your 
own file of a different format. Use the format supplied in this file. 
The format of the file will be: 
 
 
XXXXX 
 
XX/XX/XXXX XX:XX 
 
XXXXXXXXXXXX 
 
XXXXXXXXXXXX 
 
XXXXXXXXX 
 
blank line separates flights 
 
 
// Flight number e.g. VA502 
 
// Date and time 
 
// 20 char for departure airport 
 
// 20 char for arrival airport 
 
// Row number, class, seats A..F if available 
 
 
Note: Zero marks will be given for identical copies. Your program should work for any given data set. Your program should be tested with the C++ compiler provided for the practical classes. 
