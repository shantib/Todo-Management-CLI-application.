# Todo-Management-CLI-application.
Usage :-

$ ./todo add "todo item"  # Add a new todo

$ ./todo ls               # Show remaining todos

$ ./todo del NUMBER       # Delete a todo

$ ./todo done NUMBER      # Complete a todo

When a todo item is completed, it is removed from todo.txt and instead added to the done.txt text file. This file has a different format:
(i)  the letter x
(ii) the current date (UTC/GMT) in yyyy-mm-dd format
(iii)the original text

$ ./todo help             # Show usage

$ ./todo report           # Statistics
