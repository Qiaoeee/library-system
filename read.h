#ifndef _READ_H_INCLUDED 
#define _READ_H_INCLUDED
// creat two structures for students and books. 
typedef struct book
{
	char name[20];      // the name of the book
	int quan;         // how many books 
	int totquan;
	char booknum[5];   // the call number of the book
	char auth[20];      // the author's name
	struct book *pNext;
}Book;

typedef struct student
{
	char name[20];
	char id[4];
	char passw[10];
	int quan;
	struct student *pNext;
}Stud;

typedef struct record
{
	char stuname[20];
	char bookname[20];
	char booknum[20];
	char operation[10];
}Rec; 

extern Book *bHead;
extern Book *bTail;
extern Stud *sHead;
extern Stud *sTail;
extern Stud *sNow;

// read files into linked lists
extern void readStud();
extern void readBook();
extern void PrintStudent();
// switch structures
extern int OperateLibrarian(int order);
extern int OperateStudent(int order);
extern void saveInStuFile();
extern void saveInBookFile();
extern void freeStud();
extern void freeBook();
#endif
