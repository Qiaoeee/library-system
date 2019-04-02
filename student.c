
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read.h"
#include "librarian.h"
#include "print.h"
#include "student.h"

void addStud(char* name, char* id, char* passw, int quan)
{
	Stud *pTemp = (Stud*)malloc(sizeof(Stud));
	strcpy(pTemp->name, name);
	strcpy(pTemp->id, id);
	strcpy(pTemp->passw, passw);
	pTemp->quan = quan;
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
	addStud(name,id,passw,0);
}

Stud* searchStud(char* name, char*id)
{
	Stud *pTemp = (Stud*)malloc(sizeof(Stud));
	pTemp = sHead;
	int a, b;
	while(pTemp != NULL)
	{
		a = strcasecmp(pTemp->name, name);
		b = strcasecmp(pTemp->id, id);
		if(a==0 && b==0)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	} 
	
}

void setUser(char* name, char* id)
{
	sNow = searchStud(name, id);
	return;
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
	identityVertify(name, id, passw);
}

int identityVertify(char* name, char* id, char* passw)
{
	Stud *pTemp = (Stud*)malloc(sizeof(Stud));
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
			setUser(pTemp->name, pTemp->id);
			return 1;
		}
		pTemp = pTemp->pNext;
	} 
	printf("This student is not in the list.\n");
	if(1 == registerConfirm(name, id, passw))
	{
		return 0;
	}
	return 1;
}

int registerConfirm(char* name, char* id, char* passw)
{
	printf("There is no user called\"%s\". Do you want to register?\n", name);
	printf("1. Yes(Using the password above)\n");
	printf("2. Yes(Using another password)\n");
	printf("3. Quit\n");
	printf("Your choice is:");
	int quan = 0;
	int order = 0;
	scanf("%d", &order);
	switch(order)
	{
		case 1:
			addStud(name,id,passw,quan);
			setUser(name, id);
			printf("Account created successfully.\n");
			return 0;
		case 2:
			printf("Please input the password:");
			scanf("%s", passw);
			addStud(name,id,passw,quan);
			setUser(name, id);
			printf("Account created successfully.\n");
			return 0;
		case 3:
			return 1;
		default:
			printf("Invalid data.\n");
			return 1;	
	}
}

void listBook()
{
	Book* pTemp = bHead;
	bookHeaderPrint();
	while(pTemp != NULL)
	{
		printf("%-15s",pTemp->name);
		printf("%-15s",pTemp->booknum);	
		printf("%-20s", pTemp->auth);
		printf("%-15d", pTemp->quan);
		printf("%-15d", pTemp->totquan);
		printf("\n");
		pTemp = pTemp->pNext;
	}
	
}

Book* searchBook(char* name, char* booknum)
{
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = bHead;
	int a, b;
	while(pTemp != NULL)
	{
		a = strcasecmp(pTemp->name, name);
		b = strcasecmp(pTemp->booknum, booknum);
		if(a==0 && b==0)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	} 
	return NULL;
}

Book* searchNextBook(char* name, char* booknum)
{
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = bHead;
	int a, b;
	while(pTemp != NULL)
	{
		a = strcasecmp(pTemp->pNext->name, name);
		b = strcasecmp(pTemp->pNext->booknum, booknum);
		if(a==0 && b==0)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	} 
	return NULL;
}

void searchBookFunc()
{
	char name[20] = {0};
	char booknum[5] = {0};
	printf("Please input the name of the book:");
	scanf("%s", name);
	printf("Please input the number of the book:");
	scanf("%s", booknum);
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = searchBook(name, booknum);
	if(NULL == pTemp)
	{
		printf("********************************************************************************\n");
		printf("This book is not in the list. Please check the name and number carefully.\n");
	}
	else
	{
		bookHeaderPrint();
		printf("%-15s",pTemp->name);
		printf("%-15s",pTemp->booknum);	
		printf("%-20s", pTemp->auth);
		printf("%-15d", pTemp->quan);
		printf("%-15d", pTemp->totquan);
		printf("\n");
	}
}

void borrowBook()
{
	char name[20] = {0};
	char booknum[5] = {0};
	printf("Please input the name of the book:");
	scanf("%s", name);
	printf("Please input the number of the book:");
	scanf("%s", booknum);
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = searchBook(name, booknum);
	if(NULL == pTemp)
	{
		printf("********************************************************************************\n");
		printf("This book is not in the list. Please check the name and number carefully.\n");
	}
	else
	{
		if(pTemp->quan < 1)
		{
			printf("********************************************************************************\n");
			printf("This book is not available.\n");
		}
		else
		{
			pTemp->quan -= 1;
			sNow->quan += 1;
			printf("********************************************************************************\n");
			printf("Operate successfully.\n");
		}
	}
	recordOper(1, name, booknum);
}

void returnBook()
{
	char name[20] = {0};
	char booknum[5] = {0};
	printf("Please input the name of the book:");
	scanf("%s", name);
	printf("Please input the number of the book:");
	scanf("%s", booknum);
	Book *pTemp = (Book*)malloc(sizeof(Book));
	pTemp = searchBook(name, booknum);
	if(NULL == pTemp)
	{
		printf("********************************************************************************\n");
		printf("This book is not in the list. Please check the name and number carefully.\n");
	}
	else
	{
		if(sNow->quan < 1)
		{
			printf("********************************************************************************\n");
			printf("This student borrowed no book.\n");
			return;
		}
		if(pTemp->quan >= pTemp->totquan)
		{
			printf("********************************************************************************\n");
			printf("All this kind of book is already here.\n");
			return;
		}
		else
		{
			pTemp->quan += 1;
			sNow->quan -= 1;
			printf("********************************************************************************\n");
			printf("Operate successfully.\n");
		}
	}
	recordOper(2, name, booknum);
} 

void recordOper(int order, char* name, char* num)
{
	FILE* pFile = NULL;
	pFile = fopen("record.txt", "a");
	if(NULL == pFile)
	{
		printf("Open failed.\n");
		return;
	}
	//printf("Open succeed.\n");
	Rec *pTemp = (Rec*)malloc(sizeof(Rec));
	strcpy(pTemp->stuname, sNow->name);
	strcpy(pTemp->bookname, name);
	strcpy(pTemp->booknum, num);
	switch (order)
	{
		case 1:
			strcpy(pTemp->operation, "Borrow Book: ");
			break;
		case 2:
			strcpy(pTemp->operation, "Return Book: ");
			break;
		default:
			break;
	}
	
	// 该把链表中的数据写到文件里然后close了。
	char strQuan[3] = {0};
	char strTotQuan[3] = {0};
	Book *pBook = (Book*)malloc(sizeof(Book));
	pBook = searchBook(pTemp->bookname, pTemp->booknum);
	itoa(pBook->quan, strQuan, 10);
	itoa(pBook->totquan, strTotQuan, 10);
	//printf("step1.\n");
	time_t t;
	struct tm *p;
	time(&t);
	p=localtime(&t);
	char strYear[5] ={0};
	char strMon[5] ={0};
	char strDay[5] ={0};
	char strH[5] ={0};
	char strMin[5] ={0};
	char strS[5] ={0};
	//printf("step2.\n");
	itoa(1900+p->tm_year,strYear,10);
	itoa(1+p->tm_mon,strMon,10);
	itoa(p->tm_mday,strDay,10);
	itoa(p->tm_hour,strH,10);
	itoa(p->tm_min,strMin,10);
	itoa(p->tm_sec,strS,10);
	char string[300] = {0};
	strcat(string, "Student: ");
	strcat(string, pTemp->stuname);
	strcat(string, ",");
	strcat(string, pTemp->operation);
	strcat(string, pTemp->bookname);
	strcat(string, "(");
	strcat(string, pTemp->booknum);
	strcat(string, ") Time:");
	strcat(string, strYear);
	strcat(string, "-");
	strcat(string, strMon);
	strcat(string, "-");
	strcat(string, strDay);
	strcat(string, " ");
	strcat(string, strH);
	strcat(string, ":");
	strcat(string, strMin);
	strcat(string, ":");
	strcat(string, strS);
	strcat(string, ", Remained (");
	strcat(string, strQuan);
	strcat(string, "/");
	strcat(string, strTotQuan);
	strcat(string, ")\r\n");
	//printf("step3.\n");
	fwrite(string, 1, strlen(string), pFile);
	//printf("step4.\n");
	fclose(pFile);
	printf("Recorded successfully.\n");
}
