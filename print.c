
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read.h"
#include "librarian.h"
#include "print.h"
#include "student.h"

void printHelp()
{
	printf("Q: What can I do through this system?\n");
	printf("A: For the librarian, you can add and remove books from the library, list all books and list all registered users.\n");
	printf("For the users, you can register with the library, list all books, search for books, borrow a book and return a book.\n");
	printf("Q: Do I have some constraints for borrowing books?\n");
	printf("A: Each student can only borrow 10 books at most at the same time.\n");
} 

void studHeaderPrint()
{
	char strName[] = {"Name"};
	char strId[] = {"ID"};
	char strPassw[] = {"Password"};
	char strBook[] = {"Book borrowed"};
	char strQuan[] = {"Book quantity"};
	printf("********************************************************************************\n");
	printf("%-15s", strName);
	printf("%-15s",strId);
	printf("%-15s",strPassw);
	printf("%-15s",strQuan);	
	printf("\n");
}

void bookHeaderPrint()
{
	char strBook[] = {"Book"};
	char strBooknum[] = {"Number"};
	char strQuan[] = {"Quantity"};
	char strTotQuan[] = {"Total Quantity"};
	char strAuth[] = {"Author"}; 
	printf("********************************************************************************\n");
	printf("%-15s", strBook);
	printf("%-15s", strBooknum);	
	printf("%-20s", strAuth);
	printf("%-15s", strQuan);
	printf("%-15s", strTotQuan);
	printf("\n");
}

void printIdentity()
{
	printf("\tGreenday Library System \n"); 
	printf("********************************************************************************\n");
	printf("Please choose the identity\n"); 
	printf("1: I'm a student.\n"); 
	printf("2: I'm the librarian.\n");
	printf("3: Quit.\n"); 
	printf("Your identity:");
}

void printLibrarian()
{
	printf("********************************************************************************\n");
	printf("What do you want to do?\n");
	printf("1. List all books\n");
	printf("2. List all users\n");
	printf("3. Add books\n");
	printf("4. Remove books\n");
	printf("5. Help\n");
	printf("6. Quit\n\n");
	printf("Your choice is:");
} 

void printStudent()
{
	printf("********************************************************************************\n");
	printf("What do you want to do?\n");
	printf("1. List all books\n");
	printf("2. Search a book\n");
	printf("3. Borrow books\n");
	printf("4. Return books\n");
	printf("5. Help\n");
	printf("6. Quit\n\n");
	printf("Your choice is:");
}
