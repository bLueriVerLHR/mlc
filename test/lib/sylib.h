#ifndef __SYLIB_H_
#define __SYLIB_H_

#include <stdarg.h>
#include <stdio.h>
#include <sys/time.h>

/* Input & output functions */
int getint();
int getch();
int getarray(int a[]);
float getfloat();
int getfarray(float a[]);

void putint(int a), putch(int a), putarray(int n, int a[]);
void putfloat(float a);
void putfarray(int n, float a[]);

void putf(char a[], ...);

/* Timing function implementation */
#define starttime() _sysy_starttime(__LINE__)
#define stoptime() _sysy_stoptime(__LINE__)
#define _SYSY_N 1024

__attribute((constructor)) void before_main();
__attribute((destructor)) void after_main();
void _sysy_starttime(int lineno);
void _sysy_stoptime(int lineno);

#endif
