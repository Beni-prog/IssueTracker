# IssueTracker
The application simulates the development and testing of a software application, as follows:the information is in a text file. Each member 
of the team-User has a name and a type, which indicates whether the user is is a tester or a programmer. This file is manually created and it
is read when the application starts. Another file contains information about the issues reported by the testers. Each Issue has a description,
a status, the reporter and the solver.
When the application is launched, a new window is created for each user, having the user's name and type. Each window will show all the issues,
eith their description, status, reporter and solver, sorted by status and by description.
Only testers can report issues, by inputting the issue's description and pressing a button "Add". The issues's reporter will automatically
be set-the name of the tester who reported it. This operation fails if the description is empty or if there is another issue with the same 
description. The user will be informed if the operation fails.
Both programmers and users can remove issues, but only if the status is closed.
Only programmers can solve issues, by selecting the issue and pressing a buttin "Solve". This button is activated only if the status is "Open".
When an issue is solved,the name of the issue's solver will be updated to the name of the programmer who solved it. When a modification is 
made by any user, all the users will see the modified list of issues.
