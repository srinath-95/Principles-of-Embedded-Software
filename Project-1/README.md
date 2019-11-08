# Principles-Of-Embedded-Software
README file for Interactive Command line Utility

This Utility provides the leverage to examine various memory operations that can run both on Linux machine as well as FRDM board and also provides basic Unit testing on memories on Linux platform


List of Memory operations:

In the main program, the user gets to choose help or exit option where he can seek the help option to view the all the operations that one can do and exit option to exit from the functionality.
From the help menu, the user chooses the desired operation from the menu,user needs to specify the number of arguments and must specify the value of the arguments.


Operations on Memory:

Allocate Memory - The user needs to specify the no of bytes of memory that one needs to allocate. Any invalid option would return with error.

Free Memory - By choosing this option the user can free the dynamically allocated memory. Free of unallocated memory would return with an error.

Write Memory Words - This operations writes the user specified data to the specified allocated address.

Display Memory words - This operation displays the allocated memory words from the start offset to the end offset of address as specified by the user.

Invert Block - This operation inverts the data contents of the address or the offset address specified by the user

Write Pattern - This operations writes a pseudo random sequence to the specified address until the specified length of block

Verify Pattern - This operations verifies a pseudo random sequence to the specified address until the specified length of block

Write Particular offset - This operations writes the user specified data to the specified offset address.

Allocated Memory Display - This operation displays all the allocated memory along with their data value.

Exit - Exits from the utility


Unit Testing:

The unit testing part has been implemented alog with the utility where the user can run the file to if the tests were successful or not.

How to run:
Following are the commands to use to run the utility:
--> make
--> ./mem_util

Following are the commands to use to run the Unit testing:
--> make unit_test
--> ./unit_test
