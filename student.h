#ifdef _STUDENT_H
#define _STUDENT_H
// student operations
extern void addStud(char* name, char* id, char* passw, char* book, char* booknum);
extern void signUp();
extern int logIn();
extern int identityVertify(char* name, char* id, char* passw);
extern int registerConfirm(char* name, char* id, char* passw);
extern void listBook();
#endif
