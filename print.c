
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "librarian.h"
#include "print.h"
#include "student.h"

void studHeaderPrint()
{
	char strName[] = {'N','a','m','e','\0'};
	char strId[] = {'I','D','\0'};
	char strPassw[] = {'P','a','s','s','w','o','r','d','\0'};
	char strBook[] = {'B','o','o','k',' ','b','o','r','r','o','w','e','d','\0'};
	char strBooknum[] = {'B','o','o','k',' ','n','u','m','b','e','r','\0'};
	printf("%-15s", strName);
	printf("%-15s",strId);
	printf("%-15s",strPassw);
	printf("%-20s",strBook);
	printf("%-15s",strBooknum);	
	printf("\n");
}

void bookHeaderPrint()
{
	char strBook[] = {'B','o','o','k','\0'};
	char strBooknum[] = {'N','u','m','b','e','r','\0'};
	char strQuan[] = {'Q','u','a','n','t','i','t','y','\0'};
	char strAuth[] = {'A','u','t','h','o','r','\0'}; 
	printf("%-15s", strBook);
	printf("%-15s", strBooknum);	
	printf("%-15s", strQuan);
	printf("%-20s", strAuth);
	printf("\n");
}

void PrintIdentity()
{
	printf("\tGreenday Library System \n"); 
	printf("**********************************************************************\n");
	printf("Please choose the identity\n"); 
	printf("1: I'm a student.\n"); 
	printf("2: I'm the librarian.\n");
	printf("3: Quit.\n"); 
	printf("Your identity:");
}

void PrintLibrarian()
{
	printf("**********************************************************************\n");
	printf("What do you want to do?\n");
	printf("1. List all books\n");
	printf("2. List all users\n");
	printf("3. Add books\n");
	printf("4. Remove books\n");
	printf("5. Quit\n\n");
	printf("Your choice is:");
} 

void PrintStudent()
{
	printf("**********************************************************************\n");
	printf("What do you want to do?\n");
	printf("1. List all books\n");
	printf("2. Search a book\n");
	printf("3. Borrow books\n");
	printf("4. Return books\n");
	printf("5. Quit\n\n");
	printf("Your choice is:");
}
