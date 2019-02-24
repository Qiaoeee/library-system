#include <stdio.h>
#include <stdlib.h>

typedef struct book
{
	char *name;      // the name of the book
	int num;         // how many books 
	char *booknum;   // the call number of the book
	char *auth;      // the author's name
	struct book *next;
}BOOK;

typedef struct student
{
	char *name;
	int id;
	char *passw;
	struct student *next;
}STDU;



 

int main(int argc, char *argv[]) 
{
	char name, id;
	int iden;
	printf("\tGreenday Library System \n"); 
	printf("**********************************************************************\n");
	printf("Please choose the identity\n"); 
	printf("1: I'm a student.\n"); 
	printf("2: I'm the librarian.\n");
	printf("3: Quit.\n"); 
	printf("Your identity:"); 
	scanf("%i", &iden);
	getchar();
	switch(iden)
	{
		case 1:
			printf("Please input your name:");
			scanf("%s", &name);
			getchar();
			printf("Please input your id number:");
			scanf("%s", &id);
			getchar();
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			printf("Invalid data, please reopen the program and try again.");
			break;
	}
	
	return 0;
}
