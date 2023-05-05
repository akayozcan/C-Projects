#include <stdio.h>
#include <math.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
// int dt0(int t, double p, double h, int s, int w) {
//     int r = 0;
//     if (t>35 && w!=3) r = 1;
//     else if (t<=35 && s==0) r = 1;
//     return r;
// }
void MENU(){
    printf("\n[1].FIRST PROBLEM\n");
    printf("[2].SECOND PROBLEM\n");
    printf("[3].THIRD PROBLEM\n");
    printf("[0].EXIT\n");
    printf("PLEASE SELECT MENU:");
}

char dt1a(float PL,float PW,float SL,float SW){
    char r;
    if(PL<2.45){
        r='a';
    }
    else{
        if(PW<1.75 && PL<4.95 && PW<1.65) r='b';
        else r='c';
    }
    return r;
}

char dt1b(float PL,float PW,float SL,float SW){
    char r;
    if(PL<2.55){
        r='a';
    }
    else{
        if(PW<1.69 && PL<4.85) r='b';
        else r='c';
    }
    return r;
}

double dt2a(float x1,float x2,float x3,int x4 ,int x5){
    float r=1.0;
    if(x1<31.5){
        if(x2>-2.5) r=5;
        else if(x2-0.1<=x1 && x1<=x2+0.1) r=2.1;
        else r=-1.1;
    }
    else{
        if(-1<=x3 && x3<=2) r=1.4;
        else if(x4 & x5 ==1) r=-2.23;
        else r=11;
    }
    return r;
}
double dt2b(float x1,float x2,float x3,int x4 ,int x5){
    float r=1.0;
    if(12<x1 && x1<22){
        if(x3>5/3) r=-2;
        else if(x1-0.1<=x3 && x3<=x1+0.1) r=1.01;
        else r=-8;
    }
    else{
        if(x4 & x5 ==1) r=-1;
        else if(-1<=x2 && x2<=2) r=-1/7;
        else r=sqrt(2)/3;
    }
    return r;
}

int dt3a(float salary,float overtime_price,int bonus,int day,int work_hour){
    int r;
    if(salary>=10000){
        if(day<=5) r=2;
        else if(overtime_price<=(salary/30)*1.5) r=2;
        else r=1;
    }
    else{
        if(overtime_price<=(salary/30)*1.5 && bonus ==1) r=1;
        else if(overtime_price<=(salary/30)*1.5) r=0;
        else if(overtime_price>(salary/30)*1.5 && work_hour<=8) r=1;
        else r=0;
    }
    return r;
}

int dt3b(float salary,float special_pay,int annual_permit,int add_support,int day){
    int r;
    if(add_support ==1){
        if(day<=5) r=2;
        else if(annual_permit>=15 && annual_permit<=30) r=2;
        else r=1;
    }
    else{
        if(salary>10000) r=1;
        else if(special_pay>2500) r=1;
        else r=0;
    }
    return r;
}
