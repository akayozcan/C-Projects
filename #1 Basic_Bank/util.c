#include <stdio.h>
#include "util.h"

int find_divisible(int x, int y, int z){
    
    while(x%z !=0 && x<y){  //Finds the first number that can be divided by z between x and y
        x++;
    }
    if(x%z ==0){
        return x;   //If it can be divided,return this number,else return -1
    }
    else{
        return -1;  
    }
}
int find_nth_divisible(int n, int f_I, int z){
    int nth_int;                                //finds the number n steps ahead of the first number
    nth_int=f_I + z*n;
    return nth_int;
}
//=================================================================================================================
int validate_identity_number(char identity_number[ID]){
    int ID_control=0,lenght=0;
    while(identity_number[lenght]!='\0'){//lenght control
        lenght++;
    }
    if(lenght == 11){   
        ID_control++;
    }
    //----------------------------------------
    int digit,count=0,i=0,j=0;

    while(i<lenght){                //digits control
        digit = identity_number[i];
        if(digit>='0' && digit<='9'){
            count++;
        }
        i++;
    }
    if(count == 11){
        ID_control++;
    }
    //----------------------------------------
    if(identity_number[0] !=0){ //checks if the first digit is 0
        ID_control++;
    }
    //----------------------------------------
    int sum_odd_ID=0,sum_even_ID=0,operation;
    i=0;
    while(i<9){
        sum_odd_ID+=identity_number[i]-48;
        i+=2;
    }
    j=1;
    while (j<9)
    {
        sum_even_ID+=identity_number[j]-48;
        j+=2;
    }
    operation=7*sum_odd_ID -sum_even_ID;

    if(operation%10 ==identity_number[9]-48){
        ID_control++;
    }
    //-----------------------------------------
    int sum_10dig_ID=0;
    i=0;
    while (i<10){                           //checks if the mod of the sum of the first 10 digits returns the last digit
        sum_10dig_ID+=identity_number[i]-48;
        i++;
    }
    if(sum_10dig_ID%10 ==identity_number[10]-48){
        ID_control++;
    }
    //-----------------------------------------
    if(ID_control == 5){
        return 1;
    }
    else{
        return 0;
    }
}
int create_customer(char identity_number[ID], int password){//account create func...
    FILE *cfile;
    password=1453;
    cfile =fopen("customeraccount.txt","w");
    if(cfile==NULL){
        printf("File cannot open!\n");
    }
    fprintf(cfile,"%s %d",identity_number,password);
    fclose(cfile);
}
int check_login(char identity_number[ID], int password){//Check if the given password and id match the generated id and password.
    FILE *cfile;
    char ID_number[ID];
    int passw;
    cfile=fopen("customeraccount.txt","r");
    if(cfile==NULL){
        printf("File cannot open!\n");
    }
    fscanf(cfile,"%s %d",ID_number,&passw);
    fclose(cfile);
    if(ID_number[11] == identity_number[11] && passw == password){
        return 1;
    }
    else{
        return 0;
    }
}
int withdrawable_amount(float cash_amount){//part showing the amount that can be withdrawn
    float d_amount=0;
    if(cash_amount >= 50){
        while (d_amount+50<=cash_amount)
        {
            d_amount+=50;
        }
    }
    if(cash_amount >= 20){
        while(d_amount+20<=cash_amount){
            d_amount+=20;
        }
    }
    if(cash_amount >= 10){
        while(d_amount+10<=cash_amount){
            d_amount+=10;
        }
    }
    return (int)d_amount;
}
