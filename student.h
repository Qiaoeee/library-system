#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
// student operations
extern void addStud(char* name, char* id, char* passw, int quan);
extern STUD* searchStud(char* name, char*id);
extern void setUser(char* name, char* id);
extern void signUp();
extern int logIn();
extern void identityVertify(char* name, char* id, char* passw);
extern int registerConfirm(char* name, char* id, char* passw);
extern void listBook();
extern BOOK* searchBook(char* name, char* booknum);
extern void searchBookFunc();
extern void borrowBook();
#endif
