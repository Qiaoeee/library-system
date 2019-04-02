#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
// student operations
extern void addStud(char* name, char* id, char* passw, int quan);
extern Stud* searchStud(char* name, char*id);
extern void setUser(char* name, char* id);
extern void signUp();
extern int logIn();
extern int identityVertify(char* name, char* id, char* passw);
extern int registerConfirm(char* name, char* id, char* passw);
extern void listBook();
extern Book* searchBook(char* name, char* booknum);
extern Book* searchNextBook(char* name, char* booknum);
extern void searchBookFunc();
extern void borrowBook();
extern void returnBook();
void recordOper(int order, char* name, char* num);
#endif
