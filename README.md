A program made in C++ and Qt framework, also takes advantage of multithreading. 
It helps testers to store issues found in programs and for programmers to solve them.
The data is stored in 2 files: one contains the users and their role(tester or programmer), the other one contains the issues, who detected them, who solved them and if it is open or closed.
For each user the program launches a separate window which has in the title bar the name of the user and their role. 
Each user has a bar graph showing the number of opened issues and the closed ones, it is updated each time new issues are added or an existing one is closed.
The programmers can close only the opened issues and the testers can only add new ones. An issue can only be added once.
