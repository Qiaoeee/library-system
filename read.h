#ifndef _READ_H_INCLUDED 
#define _READ_H_INCLUDED
// creat two structures for students and books. 
typedef struct book
{
	char name[20];      // the name of the book
	int quan;         // how many books 
	char booknum[5];   // the call number of the book
	char auth[20];      // the author's name
	struct book *pNext;
}BOOK;

typedef struct student
{
	char name[20];
	char id[5];
	char passw[10];
	int quan;
	struct student *pNext;
}STUD;

extern BOOK *bHead;
extern BOOK *bTail;
extern STUD *sHead;
extern STUD *sTail;
extern STUD *sNow;

// read files into linked lists
extern void readStud();
extern void readBook();
extern void PrintStudent();
// switch structures
extern int OperateLibrarian(int order);
extern int OperateStudent(int order);
#endif
