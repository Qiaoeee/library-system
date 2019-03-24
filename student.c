
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "librarian.h"
#include "print.h"
#include "student.h"

void addStud(char* name, char* id, char* passw, char* book, char* booknum)
{
	STUD *pTemp = (STUD*)malloc(sizeof(STUD));
	strcpy(pTemp->name, name);
	strcpy(pTemp->id, id);
	strcpy(pTemp->passw, passw);
	strcpy(pTemp->book, book);
	strcpy(pTemp->booknum, booknum);
	pTemp->pNext = NULL;
	if(NULL == sHead || NULL == sTail)
	{
		sHead = pTemp;
		sTail = pTemp;
	}
	else
	{
		sTail->pNext = pTemp;
		sTail = pTemp;
	}
}

void signUp()
{
	char name[20];
	char id[4];
	char passw[20];
	printf("Please input your name:");
	gets(name);
	printf("Please input your id number:");
	scanf("%s", id);
	printf("Please input your password:");
	scanf("%s", passw);
	printf("%-15s",name);
	printf("%-15s",id);
	printf("%-15s",passw);
	addStud(name,id,passw,NULL,NULL);
}

int logIn()
{
	char name[20] = {0};
	char id[5] = {0};
	char passw[10] = {0};
	printf("Please input your name:");
	scanf("%s", name);
	printf("Please input your id number:");
	scanf("%s", id);
	printf("Please input your password:");
	scanf("%s", passw);
	//printf("%s %s %s", name, id, passw);
	if(identityVertify(name, id, passw) == 1)
	{
		return 1;
	}
}

int identityVertify(char* name, char* id, char* passw)
{
	STUD *pTemp = (STUD*)malloc(sizeof(STUD));
	pTemp = sHead;
	int a, b, c;
	while(pTemp != NULL)
	{
		a = strcasecmp(pTemp->name, name);
		b = strcasecmp(pTemp->id, id);
		c = strcasecmp(pTemp->passw, passw);
		if(a==0 && b==0 && c==0)
		{
			printf("This student is in the list.\n");
			return 1;
		}
		pTemp = pTemp->pNext;
	} 
	printf("This student is not in the list.\n");
	while(1 == registerConfirm(name, id, passw)){};
	return 0;
}

int registerConfirm(char* name, char* id, char* passw)
{
	printf("There is no user called\"%s\". Do you want to reegister?\n", name);
	printf("1. Yes(Using the password above)\n");
	printf("2. Yes(Using another password)\n");
	printf("3. Quit\n");
	printf("Your choice is:");
	int order = 0;
	scanf("%d", &order);
	switch(order)
	{
		case 1:
			addStud(name,id,passw,NULL,NULL);
			printf("Account created successfully.\n");
			return 0;
		case 2:
			printf("Please input the password:");
			scanf("%s", passw);
			addStud(name,id,passw,NULL,NULL);
			printf("Account created successfully.\n");
			return 0;
		case 3:
			return 0;
		default:
			printf("Invalid data.");
			return 1;	
	}
}

void listBook()
{
	BOOK* pTemp = bHead;
	bookHeaderPrint();
	while(pTemp != NULL)
	{
		printf("%-15s",pTemp->name);
		printf("%-15s",pTemp->booknum);	
		printf("%-15d", pTemp->quan);
		printf("%-20s", pTemp->auth);
		printf("\n");
		pTemp = pTemp->pNext;
	}
}
