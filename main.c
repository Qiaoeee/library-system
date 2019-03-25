
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "librarian.h"
#include "print.h"
#include "student.h"

int main(int argc, char *argv[]) 
{
	int ident, return1 = 1, return2 = 1;
	int order1 = 0, order2 = 0;
	PrintIdentity();
	scanf("%d", &ident);
	switch(ident)
	{
		case 1:
			readBook();
			readStud();
			logIn();
			while(0 != return1)
			{
				PrintStudent();
				scanf("%d", &order1);
				return1 = OperateStudent(order1);
			}
			break;
		case 2:
			readBook();
			readStud();
			while(0 != return2)
			{
				PrintLibrarian();
				scanf("%d", &order2);
				return2 = OperateLibrarian(order2);
			}
			break;
		case 3:
			return 0;
		default:
			printf("Invalid data. Please retry.");
			break;
	}
	return 0;
}
