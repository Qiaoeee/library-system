#ifdef _READ_H
#define _READ_H
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
	char book[20];
	char booknum[5];
	struct student *pNext;
}STDU;
// creat head pointers and tail pointers for two linked lists separately.
extern BOOK *bHead = NULL;
extern BOOK *bTail = NULL;
extern STDU *sHead = NULL;
extern STDU *sTail = NULL;
// read files into linked lists
extern void readStud();
extern void readBook();
extern void PrintStudent();
// switch structures
extern int OperateLibrarian(int order);
extern int OperateStudent(int order);
#endif
