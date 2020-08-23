James Kistner
Rene German
CPSC 350-01
29 September 2018

For this assignment I split up the program into different parts and different classes. For every game mode there is a class to accompany it as well as a .h file. There was also a grid class and main of course. I thought this approach was the best at first, but as I got further into the program I realized that inheritance could've been very useful here as I was copy pasting similar code into each game mode class. The main problem I had when doing this assignment was trying to use an object copy constructor in another class. This gave me trouble throughout the program because I couldn't test other parts while the copy wasn't working. Eventually I decided to create a grid object within each game mode class which solved my problem instantly.

Some notes about my program:
- If you select the enter between each generation, you have to hit enter once the first time, then enter twice every time after (idk why).
- Any file can be read in if the first two lines contain the rows and columns followed by the '-' and 'X' on the next lines. If anything is read in that isn't 'X' or '-', that index in the array is set to '-'
- I didn't implment command line into the main (I don't understand why I would need to implement command line on this assignment, but if you could explain why I need it that'd be great)

I worked by myself on this project, but I used these following links to help with the majority of the problems I encountered in this assignment. I also went to a few office hours with you, Rene, and tried to get help from the tutoring center, but they didn't help at all.


http://www.cplusplus.com/reference/cctype/isdigit/
https://stackoverflow.com/questions/27496934/c-assigning-value-to-multidimensional-array
http://www.cplusplus.com/forum/beginner/1988/
http://www.cplusplus.com/reference/cctype/toupper/
https://stackoverflow.com/questions/30720594/deleting-a-dynamically-allocated-2d-array
https://gradestack.com/Programming-in-C-/C-and-Memory-Models/Dynamic-Objects/21205-4330-52974-study-wtw