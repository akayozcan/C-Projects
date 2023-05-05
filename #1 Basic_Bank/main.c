#include <stdio.h>
#include "util.h"

int main(){

    /*_______________________________________________ First Part _______________________________________________________________________________*/
    int x,y,z,n,f_I;
    printf("========================= PART 1 =========================\n");
    printf("Enter the first integer:");
    scanf("%d",&x);
    printf("Enter the second integer:");
    scanf("%d",&y);
    printf("Enter the divisor:");
    scanf("%d",&z);

    if(find_divisible(x,y,z) == -1 || y<x){  //Checks if a number is divisible between given digits
        printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
    }
    else{
        f_I = find_divisible(x,y,z);
        printf("The first integer between %d and %d divided by %d is %d\n",x,y,z,f_I);
        printf("Enter the number how many next:");
        scanf("%d",&n);
        if(find_nth_divisible(n,f_I,z)<=y){     //Calculates the number after saying forward n times
            printf("The %d. integer between %d and %d divided by %d is %d\n",n+1,x,y,z,find_nth_divisible(n,f_I,z));
        }
        else{
            printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
        }
    }
    /*_______________________________________________ Second Part _______________________________________________________________________________*/
    char identity_number[ID],create_ID_number[ID];
    int password,create_password;
    float cash_amount;
    int count=0,check;
    
    printf("\n========================= PART 2 =========================\n");
    do{ //It checks whether the form of the ID number is suitable. If it is not, it writes "invalid id"
        if(count>0)
            printf("\nID number not available!\n");
        printf("Enter your ID number to create a new customer account:");
        scanf("%s",create_ID_number);
        printf("Enter your password to create a new customer account:");
        scanf("%d",&create_password);
        count++;
    }
    while(validate_identity_number(create_ID_number) !=1);
    create_customer(create_ID_number,create_password);
    printf("-Account created-\n\n");


    printf("Enter your identity number:");
    scanf("%s",identity_number);
    printf("Enter your password:");
    scanf("%d",&password);

    if(check_login(identity_number,password)==1){ //Check if the given password and id match the generated id and password.      
        printf("-Login Successful-\n\n");
    }
    else{
        do{
            printf("Invalid identity number or password!\n");
            printf("Enter your identity number:");
            scanf("%s",identity_number);
            printf("Enter your password:");
            scanf("%d",&password);
        }
        while(check_login(identity_number,password) ==1);
    }

    printf("Enter your withdraw amount:");//part showing the amount that can be withdrawn
    scanf("%f",&cash_amount);
    printf("Withdrawable amount is %d\n",withdrawable_amount(cash_amount));

    return 0;
}
