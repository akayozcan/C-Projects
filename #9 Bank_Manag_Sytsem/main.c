#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int arr_count[MAX][3]={0};//array holding the number of credits
float arr_loans[MAX][2]={0};//array holding the loan amount

union Person
{
    char name[MAX];
    char address[MAX];
    int phone;
};
union Loan
{
    float amount;
    float interestRate;
    int period;
};
typedef struct
{
    union Person Customer;
    union Loan Loans[3];
}BankAccount;

BankAccount bankAccount[MAX];//global struct

void addCustomer(int current_size);//Add customer in bank account system
void listCustomers(int size);//print customer ID and name on the screen...
void newLoan(int size);//the functon of the loan application
float calculateLoan(float amount, int period, float interestRate);//function that calculate loan amount using recursive...
void getReport(int size,int selection);//Function to print user and credit information...

int main(){

    int count_customer=0,selection=0;
    
    printf("=========================================\n");
    printf("  Welcome to the Bank Management System  \n");
    printf("=========================================\n");

    do{
        printf("\n1.List All Customers\n");
        printf("2.Add New Customer\n");
        printf("3.New Loan Application\n");
        printf("4.Report Menu\n");
        printf("5.Exit System\n");
        printf("Select Menu:");
        scanf("%d",&selection);

        switch(selection){
            case 1:
                listCustomers(count_customer);
                break;
            case 2:
                addCustomer(count_customer);
                count_customer++;
                break;
            case 3:
                newLoan(count_customer);
                break;
            case 4:
                printf("\n1.Customer List\n");
                printf("2.Loan detail\n");
                printf("Select Menu:");
                scanf("%d",&selection);
                getReport(count_customer,selection);
                break;
            default:
                printf("Wrong Selection! Try again...\n");
        }

    }while(selection != 5);
    return 0;
}

void addCustomer(int current_size){//Add customer in bank account system
    FILE *file;
    file=fopen("customer.txt","a");//copy customer info in the customer.txt file...
    if(file==NULL) printf("File cannot open!\n");

    printf("Please enter Customer Address:");
	fflush(stdin);
	scanf(" %[^\n]%*c",bankAccount[current_size].Customer.address);
    fprintf(file,"%s ",bankAccount[current_size].Customer.address);

	printf("Please enter Customer Phone:");
	fflush(stdin);
	scanf("%d",&bankAccount[current_size].Customer.phone);
    fprintf(file,"%d ",bankAccount[current_size].Customer.phone);

    printf("Please enter Customer Name:");
	fflush(stdin);
	scanf(" %[^\n]%*c",bankAccount[current_size].Customer.name);
    fprintf(file,"%s\n",bankAccount[current_size].Customer.name);

    fclose(file);
}

void listCustomers(int size){//print customer ID and name on the screen...
    int i;
    float total=0;
    printf("List of All Customers:\n\n");
    for(i=0;i<size;i++){
        printf("Customer ID=%d\n",i+1);
        printf("Customer Name=%s\n\n",bankAccount[i].Customer.name);
    }
}

void newLoan(int size){//the functon of the loan application
    FILE*file;
    char name[MAX];
    int i=0,count=0;
    float total_loan,total=0;

    file=fopen("loan.txt","a");//copy loan info in the loan.txt file...
    if(file ==NULL) printf("File cannot open!");

    printf("Please enter Customer Name:");
    fflush(stdin);
	scanf(" %[^\n]%*c",name);

    for(i=0;i<size;i++){
        if(strcmp(bankAccount[i].Customer.name,name)==0){
            for(int j=0;j<3;j++){
                if(arr_count[i][j] !=0) count++;
            }
            if(count==3){
                printf("You cannot apply for more than 3 loans!!!\n");
                break;
            }
            printf("\nYou currently have %d loans...(You can withdraw a max of 3 loans)\n",count);
            fprintf(file,"%d ",i+1);

            printf("\nEnter the period of the loan:");
            scanf("%d",&bankAccount[i].Loans[count].period);
            fprintf(file,"%d ",bankAccount[i].Loans[count].period);

            printf("Enter the interest rate of the loan you will withdraw:");
            scanf("%f",&bankAccount[i].Loans[count].interestRate);
            fprintf(file,"%f ",bankAccount[i].Loans[count].interestRate);

            printf("Please enter the loan amount you want to get:");
            scanf("%f",&bankAccount[i].Loans[count].amount);
            fprintf(file,"%f\n",bankAccount[i].Loans[count].amount);

            printf("# Your loan application is successful #\n");
            arr_count[i][count]=1;
        }
    }
    fclose(file);
}

float calculateLoan(float amount, int period, float interestRate){//function that calculate loan amount using recursive...
    if(period==0) return amount;
    amount=amount*(1.0+interestRate);
    return calculateLoan(amount,period-1,interestRate);
}

void getReport(int size,int selection){//Function to print user and credit information...
    FILE*fptr1;
    FILE*fptr2;
    char address[MAX],name[MAX],name_loan[MAX];
    int i=0,phone,period,ID;
    float amount,interestRate,sum_amount=0,temp;

    fptr1=fopen("customer.txt","r");
    if(fptr1==NULL) printf("File cannot open!\n");
    
    switch (selection)//choice came from main
    {
    case 1:
        printf("LIST OF CUSTOMERS:\n------------------------------\n");
        while(!feof(fptr1)){//reads to the end of the file 
            sum_amount=0;
            fscanf(fptr1,"\n%s %d %s",address,&phone,name);
            printf("Customer ID = %d\n",i+1);
            printf("Customer Name = %s\n",name);
            printf("Customer Phone = %d\n",phone);
            printf("Customer Address = %s\n",address);
            printf("Loans=[");

            int j=0;
            fptr2=fopen("loan.txt","r");
            if(fptr2==NULL) printf("File cannot open!\n");

            while(!feof(fptr2)){
                fscanf(fptr2,"%d %d %f %f\n",&ID,&period,&interestRate,&amount);//It finds the user slected from the file and collects 
                if(ID==i+1){                                                    //the credit amounts and prints them on the screen...
                    temp=calculateLoan(amount,period,interestRate);
                    sum_amount+=temp;
                    printf("%.2f+ ",temp);
                }
                arr_loans[i][0]=sum_amount;
                arr_loans[i][1]=period;
            }
            fclose(fptr2);
            printf("] => %.2f\n\n",sum_amount);
            i++;
        }
        fclose(fptr1);
        break;

    case 2:
        i=0;
        printf("Enter Customer Name:");
        fflush(stdin);
        scanf(" %[^\n]%*c",name_loan);

        fptr1=fopen("customer.txt","r");
        if(fptr1==NULL) printf("File cannot open!\n");

        while(!(feof(fptr1))){//Shows the credit details in detail according to the entered user...
            fscanf(fptr1,"%s %d %s\n",address,&phone,name);

            if(strcmp(name_loan,name)==0){
                printf("Total Credit Value = %.4f\n",arr_loans[i][0]);
                arr_loans[i][0]/=arr_loans[i][1];
                period=(int)arr_loans[i][1];//change type float to int...

                for(int k=0;k<period;k++){
                    printf("%2d.Month Installment = %.4f\n",k+1,arr_loans[i][0]);
                }
            }
            i++;
        }
        fclose(fptr1);
    default:
        break;
    }
}