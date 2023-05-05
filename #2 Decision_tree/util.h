#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
//int dt0(int t, double p, double h, char s, int w);

char dt1a(float PL,float PW,float SL,float SW);
char dt1b(float PL,float PW,float SL,float SW);

double dt2a(float x1,float x2,float x3,int x4 ,int x5);
double dt2b(float x1,float x2,float x3,int x4 ,int x5);

int dt3a(float salary,float overtime_price,int bonus,int day,int work_hour);
int dt3b(float salary,float special_pay,int annual_permit,int add_support,int day);

void MENU();


#endif /* _UTIL_H_ */
