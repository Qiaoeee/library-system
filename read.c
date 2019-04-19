
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read.h"
#include "librarian.h"
#include "print.h"
#include "student.h"
// creat head pointers and tail pointers for two linked lists separately.
Book *bHead = NULL;
Book *bTail = NULL;
Stud *sHead = NULL;
Stud *sTail = NULL;
Stud *sNow = NULL;

void readStud()
{
	FILE* pStuFile = fopen("student.txt", "rb+");
	if(NULL == pStuFile)
	{
		printf("Open failed, please retry.\n");
		return;
	}
	char buffer[70];
	fgets(buffer, 70, pStuFile);
	while(NULL != fgets(buffer, 70, pStuFile))
	{
		int i, count = 0; // 'count' for the order of commas
		int j = 0;
		int line = 0;
		char strName[20] = {0};
		char strId[5] = {0};
		char strPassw[10] = {0};
		char strQuan[15] = {0};
		int intQuan = 0; 
		for(i = 0; buffer[i] != '\r'; i++)
		{
			if(buffer[i] == ',')
			{
				count++;
				j = i + 1;
			}
			else if(0 == count)
			{
				strName[i] = buffer[i];
			}
			else if(1 == count)
			{
				strId[i-j] = buffer[i];
			}
			else if(2 == count)
			{
				strPassw[i-j] = buffer[i];
			}
			else if(3 == count)
			{
				strQuan[i-j] = buffer[i];
			}
		} 
		intQuan = atoi(strQuan);
		addStud(strName,strId,strPassw,intQuan);
		
	}
	fclose(pStuFile); // to write into the file.
}

void readBook()
{
	FILE* pBookFile = fopen("book.txt", "rb+");
	if(NULL == pBookFile)
	{
		printf("Open failed, please retry.\n");
		return;
	}
	char buffer[60];
	fgets(buffer, 60, pBookFile);
	while(NULL != fgets(buffer, 60, pBookFile))
	{
		int i, count = 0; // 'count' for the order of commas
		int j = 0; 
		char strBook[20] = {0};
		char strBooknum[7] = {0};
		char strAuth[10] = {0};
		char strQuan[3] = {0};
		char strTotQuan[3] = {0};
		for(i = 0; buffer[i] != '\r'; i++)
		{
			if(buffer[i] == ',')
			{
				count++;
				j = i + 1;
			}
			else if(0 == count)
			{
				strBook[i] = buffer[i];
			}
			else if(1 == count)
			{
				strBooknum[i-j] = buffer[i];
			}
			else if(2 == count)
			{
				strAuth[i-j] = buffer[i];
			}
			else if(3 == count)
			{
				strQuan[i-j] = buffer[i];
			}
			else if(4 == count)
			{
				strTotQuan[i-j] = buffer[i];
			}
		} 
		addBook(strBook,strBooknum,strAuth,atoi(strQuan),atoi(strTotQuan));
	}
	fclose(pBookFile); // to write into the file.
}

int operateLibrarian(int order)
{
	switch(order)
	{
		case 1:
			listBook();
			return 1;
		case 2:
			listUser();
			return 1;
		case 3:
			addBookInTheList();
			return 1;
		case 4:
			removeBook();
			return 1;
		case 5:
			printHelp();
			return 1;
		case 6:
			return 0;
		default:
			printf("Invalid data.");
			break;
	}
	return 0;
}

int operateStudent(int order)
{
	switch(order)
	{
		case 1:
			listBook();
			return 1;
		case 2:
			searchBookFunc();
			return 1;
		case 3:
			borrowBook();
			return 1;
		case 4:
			returnBook();
			return 1;
		case 5:
			printHelp();
			return 1;
		case 6:
			return 0;
		default:
			printf("Invalid data.");
			break;
	}
	return 0;
}

void saveInStuFile()
{
	if(NULL == sHead)
	{
		printf("There is no student.\n");
		return;
	}
	FILE* pFile = NULL;
	pFile = fopen("student.txt", "wb+");
	if(NULL == pFile)
	{
		printf("Open failed.\n");
		return;
	}
	Stud *pTemp = (Stud*)malloc(sizeof(Stud));
	pTemp = sHead;
	char header[70] = "Name,ID,Password,Book quantity\r\n";
	fwrite(header, 1, strlen(header), pFile);
	while(NULL != pTemp)
	{
		char string[70] = {0};
		char strQuan[5] = {0};
		strcpy(string, pTemp->name);
		strcat(string, ",");
		strcat(string, pTemp->id);
		strcat(string, ",");
		strcat(string, pTemp->passw);
		strcat(string, ",");
		itoa(pTemp->quan, strQuan, 10);
		strcat(string, strQuan);
		strcat(string, "\r\n");
		fwrite(string, 1, strlen(string), pFile);
		pTemp = pTemp->pNext;
	}
	fclose(pFile);
	//printf("Operate successfully.\n");
} 

void saveInBookFile()
{
	if(NULL == bHead)
	{
		printf("There is no student.\n");
		return;
	}
	FILE* pFile = NULL;
	pFile = fopen("book.txt", "wb+");
	if(NULL == pFile)
	{
		printf("Open failed.\n");
		return;
	}
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = bHead;
	char header[70] = "Book,Number,Author,Quantity,Total Quantity\r\n";
	fwrite(header, 1, strlen(header), pFile);
	while(NULL != pTemp)
	{
		char string[70] = {0};
		char strQuan[5] = {0};
		char strTotQuan[5] = {0};
		itoa(pTemp->quan, strQuan, 10);
		itoa(pTemp->totquan, strTotQuan, 10);
		strcpy(string, pTemp->name);
		strcat(string, ",");
		strcat(string, pTemp->booknum);
		strcat(string, ",");
		strcat(string, pTemp->auth);
		strcat(string, ",");
		strcat(string, strQuan);
		strcat(string, ",");
		strcat(string, strTotQuan);
		strcat(string, "\r\n");
		fwrite(string, 1, strlen(string), pFile);
		pTemp = pTemp->pNext;
	}
	fclose(pFile);
	//printf("Operate successfully.\n");
}

void freeStud()
{
	Stud *pTemp = (Stud*)malloc(sizeof(Stud));
	pTemp = sHead;
	while(NULL != pTemp)
	{
		Stud* pFree = pTemp;
		pTemp = pTemp->pNext;
		free(pFree);
	}
	sHead = NULL;
	sTail = NULL;
}

void freeBook()
{
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = bHead;
	while(NULL != pTemp)
	{
		Book* pFree = pTemp;
		pTemp = pTemp->pNext;
		free(pFree);
	}
	bHead = NULL;
	bTail = NULL;
}
