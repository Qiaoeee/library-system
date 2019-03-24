
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "librarian.h"
#include "read.h"
#include "print.h"
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
		char strId[3] = {0};
		char strPassw[10] = {0};
		char strBook[20] = {0};
		char strBooknum[15] = {0};
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
				strBook[i-j] = buffer[i];
			}
			else if(4 == count)
			{
				strBooknum[i-j] = buffer[i];
			}
		} 
		addStud(strName,strId,strPassw,strBook,strBooknum);
		
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
		char strQuan[3] = {0};
		char strAuth[10] = {0};
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
				strQuan[i-j] = buffer[i];
			}
			else if(3 == count)
			{
				strAuth[i-j] = buffer[i];
			}
		} 
		//printf("%-15s", strBook);
		//printf("%-15s", strBooknum);
		//printf("%-15s", strQuan);
		//printf("%-20s", strAuth);
		//printf("\n");
		addBook(strBook,strBooknum,strAuth,atoi(strQuan));
	}
	fclose(pBookFile); // to write into the file.
}

int OperateLibrarian(int order)
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
			//IncreaseBook();
			return 1;
		case 4:
			//RemoveBook();
			return 1;
		case 5:
			return 0;
		default:
			printf("Invalid data.");
			break;
	}
	return 0;
}

int OperateStudent(int order)
{
	switch(order)
	{
		case 1:
			listBook();
			return 1;
		case 2:
			//searchBook();
			return 1;
		case 3:
			//borrowBook();
			return 1;
		case 4:
			//returnBook();
			return 1;
		case 5:
			return 0;
		default:
			printf("Invalid data.");
			break;
	}
	return 0;
}
