
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "librarian.h"
#include "read.h"
#include "print.h"

void addStud(char* name, char* id, char* passw, char* book, char* booknum)
{
	STDU *pTemp = (STDU*)malloc(sizeof(STDU));
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
	/*
	printf("%-15s", &pTemp->name);
	printf("%-15i", &pTemp->id);
	printf("%-15s", &pTemp->passw);
	printf("%-20s", &pTemp->book);
	printf("%-15s", &pTemp->booknum);
	printf("\n");*/
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
	if(identityVertify(name, id, passw) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int identityVertify(char* name, char* id, char* passw)
{
	STDU* pTemp = sHead;
	while(pTemp != NULL)
	{
		if(pTemp->name==name && pTemp->id==id && pTemp->passw==passw)
		{
			return 1;
		}
	} 
	return 0;
}

int registerConfirm(char* name, char* id, char* passw)
{
	printf("There is no user called\"%s\". Do you want to reegister?\n", name);
	printf("1. Yes(Using the password above)\n");
	printf("2. Yes(Using another password)\n");
	printf("3. Quit");
	int order = 0;
	switch(order)
	{
		case 1:
			addStud(name,id,passw,NULL,NULL);
			return 0;
		case 2:
			printf("Please input the password:");
			scanf("%s", passw);
			addStud(name,id,passw,NULL,NULL);
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
