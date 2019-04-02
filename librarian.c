
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read.h"
#include "librarian.h"
#include "print.h"
#include "student.h"

void addBook(char* name, char* booknum, char* auth, int quan, int totquan)
{
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp->quan = quan;
	pTemp->totquan  = totquan;
	strcpy(pTemp->auth, auth);
	strcpy(pTemp->name, name);
	strcpy(pTemp->booknum, booknum);
	pTemp->pNext = NULL;
	if(NULL == bHead || NULL == bTail)
	{
		bHead = pTemp;
		bTail = pTemp;
	}
	else
	{
		bTail->pNext = pTemp;
		bTail = pTemp;
	}
}

void listUser()
{
	Stud* pTemp = sHead;
	studHeaderPrint();
	while(pTemp != NULL)
	{
		char strQuan[15] = {0};
		printf("%-15s", pTemp->name);
		printf("%-15s",pTemp->id);
		printf("%-15s",pTemp->passw);
		printf("%-15d",pTemp->quan);	
		printf("\n");
		pTemp = pTemp->pNext;
	}
}

void addBookInTheList()
{
	char name[20] = {0};
	char booknum[5] = {0};
	char auth[20] = {0};
	int quan = 0;
	printf("Please input the name of the book:");
	scanf("%s", name);
	printf("Please input the number of the book:");
	scanf("%s", booknum);
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = searchBook(name, booknum);
	if(NULL == pTemp)
	{
		
		printf("Please input the author of the book:");
		scanf("%s", auth);
		printf("Please input the adding quantity of the book:");
		scanf("%d", &quan);
		addBook(name, booknum, auth, quan, quan);
		printf("********************************************************************************\n");
		printf("Operate successfully.\n");
	}
	else
	{
		printf("This book is already in the list.\n");
		printf("Please input the adding quantity of the book:");
		scanf("%d", &quan);
		pTemp->quan += quan;
		pTemp->totquan += quan;
		printf("********************************************************************************\n");
		printf("Operate successfully.\n");
	}
}

void removeBook()
{
	char name[20] = {0};
	char booknum[5] = {0};
	char auth[20] = {0};
	int quan = 0;
	int order;
	printf("Please input the name of the book:");
	scanf("%s", name);
	printf("Please input the number of the book:");
	scanf("%s", booknum);
	printf("What do you want to do with this kind of book:\n");
	printf("1. Remove the entire kind.\n");
	printf("2. Decrease the quantity of it.\n");
	printf("Your choice is:");
	scanf("%d", &order);
	switch(order)
	{
		case 1:
		{
			Book *pTar = (Book*)malloc(sizeof(Book));
			pTar = searchBook(name, booknum);
			Book *pTemp = (Book*)malloc(sizeof(Book));
			pTemp = searchNextBook(name, booknum);
			if(NULL == pTemp)
			{
				if(bHead == pTar)
				{
					bHead = pTar->pNext;
					free(pTar);
					printf("********************************************************************************\n");
					printf("Operate successfully.\n");
				}
				else
				{
					printf("********************************************************************************\n");
					printf("Can not find this book.\n");
				}
			}
			else
			{
				if(bTail == pTar)
				{
					bTail = pTemp;
					free(pTar);
					printf("********************************************************************************\n");
					printf("Operate successfully.\n");
				}
				else
				{
					pTemp->pNext = pTar->pNext;
					free(pTar);
					printf("********************************************************************************\n");
					printf("Operate successfully.\n");
				}
			}
			break;
		}
		case 2:
		{
			int dquan;
			Book *pTar = (Book*)malloc(sizeof(Book));
			pTar = searchBook(name, booknum);
			printf("Please input the decreasing quantity of the book:");
			scanf("%d", &dquan);
			if(pTar->quan > 0)
			{
				pTar->quan -= dquan;
				printf("********************************************************************************\n");
				printf("Operate successfully.\n");
			}
			break;
		}
		default:
			printf("Invalid data.\n");
			break;
	}
	
}
