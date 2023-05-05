#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main() {

    int operation;

    float PL,PW,SL,SW;  //Data type of first problem
    char check1_a,check1_b;

    float x1,x2,x3;    //Data type of second problem
    int x4,x5;
    double check2_a,check2_b;
    double dif_result;

    float salary,overtime_price,special_pay;   //Data type of third problem
    int bonus,day,work_hour,add_support,annual_permit;
    int check3_a,check3_b;
    
    while(operation !=0){
        MENU();
        scanf("%d",&operation);
        switch(operation){
        case 1:
            /*-----------------------------------------  First Problem  ----------------------------------------------------*/
            printf("Please enter the PL,PW,SL,SW (real numbers) values respectively:");
            scanf("%f %f %f %f",&PL,&PW,&SL,&SW);
            check1_a=dt1a(PL,PW,SL,SW);
            check1_b=dt1b(PL,PW,SL,SW);
            if(check1_a == check1_b){     //I determined its type by typing in the equations and comparisons.
                if(check1_a == 'a') printf("Type of iris flower is Setosa.\n");
                else if(check1_a == 'b') printf("Type of iris flower is Versicolor.\n");
                else printf("Type of iris flower is Virginica.\n");
            }
            else{
                if(check1_a == 'a'){
                    if(check1_b == 'b') printf("The iris type could be Setosa and Versicolor.\n");
                    else printf("The iris type could be Setosa and Virginica.\n");
                }
                else if(check1_a == 'b'){
                    if(check1_b == 'a') printf("The iris type could be Versicolor and Setosa.\n");
                    else printf("The iris type could be Versicolor and Virginica.\n"); 
                }
                else{
                    if(check1_b == 'a') printf("The iris type could be Virginica and Setosa.\n");
                    else printf("The iris type could be Virginica and Versicolor.\n"); 
                }
            }
            break;
        
        case 2:
            /*-----------------------------------------  Second Problem  ----------------------------------------------------*/
            printf("Please enter x1,x2,x3(real numbers) and x4,x5(binary values 0-1) respectivly:");
            scanf("%f %f %f %d %d",&x1,&x2,&x3,&x4,&x5);
            check2_a=dt2a(x1,x2,x3,x4,x5);
            check2_b=dt2b(x1,x2,x3,x4,x5);
            dif_result=check2_a-check2_b;
            if(dif_result<0) dif_result=-dif_result;

            if(dif_result<=CLOSE_ENOUGH){
                printf("Result : %.2lf\n",(check2_a+check2_b)/2);
            }
            else{
                printf("Results are %.2lf and %.2lf\n",check2_a,check2_b);
            }
            break;
            
        case 3:
            /*-----------------------------------------  Third Problem  ----------------------------------------------------*/
            printf("Welcome to the program that evaluates the conditions of the job you will apply for.\n\n");
            printf("Enter the salary of job:");
            scanf("%f",&salary);
            printf("How many days will you work a week:");
            scanf("%d",&day);
            printf("How many hours will you work a day:");
            scanf("%d",&work_hour);
            printf("Enter the overtime price of job:");
            scanf("%f",&overtime_price);
            printf("Is there free coffee, snacks and food at work?(yes-1,no-0):");
            scanf("%d",&bonus);
            printf("Is there accommodation and road support?(yes-1 no-0):");
            scanf("%d",&add_support);
            printf("Annual leave amount:");
            scanf("%d",&annual_permit);
            printf("How much is the Christmas and special days premium?(Average-2500):");
            scanf("%f",&special_pay);
            printf("\n");


            check3_a=dt3a(salary,overtime_price,bonus,day,work_hour);
            check3_b=dt3b(salary,special_pay,annual_permit,add_support,day);

            if(check3_a == check3_b){     //I determined its result by typing in the equations and comparisons.
                if(check3_a == 0) printf("Working conditions are excellent.\n");
                else if(check3_b == 1) printf("Working conditions are average.\n");
                else printf("Working conditions are insufficient.\n");
            }
            else{
                if(check3_a == 0){
                    if(check3_b == 1) printf("Working conditions:\nFirst:Excellent\nSecond:Average\n");
                    else printf("Working conditions:\nFirst:Excellent\nSecond:Insufficient\n");
                }
                else if(check3_a == 1){
                    if(check3_b == 0) printf("Working conditions:\nFirst:Average\nSecond:Excellent\n\n");
                    else printf("Working conditions::\nFirst:Average\nSecond:Insufficient\n"); 
                }
                else{
                    if(check3_b == 0) printf("Working conditions:\nFirst:Insufficient\nSecond:Excellent\n");
                    else printf("Working conditions:\nFirst:Insufficient\nSecond:Average\n"); 
                }
            }
            break;

        default:
            break;
    }
}
    return 0;
}
