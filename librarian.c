
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "librarian.h"
#include "read.h"
#include "print.h"

void addBook(char* name, char* booknum, char* auth, int quan)
{
	BOOK *pTemp = (BOOK*)malloc(sizeof(BOOK));
	pTemp->quan = quan;
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
	STDU* pTemp = sHead;
	studHeaderPrint();
	while(pTemp != NULL)
	{
		printf("%-15s", pTemp->name);
		printf("%-15s",pTemp->id);
		printf("%-15s",pTemp->passw);
		printf("%-20s",pTemp->book);
		printf("%-15s",pTemp->booknum);	
		printf("\n");
		pTemp = pTemp->pNext;
	}
}