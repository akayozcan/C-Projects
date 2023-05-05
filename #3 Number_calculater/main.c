#include <stdio.h>
#include <math.h>
//30 945 21 173 42 952 425
int sum(int n1,int n2,int flag);
int multi(int n1,int n2,int flag);
int isprime(int a);
void write_file(FILE *fptr,int number);
void print_file(FILE *fptr);
int numbers_count(FILE *fptr);
void sort_file(FILE *fptr,FILE * ftemp);
void change_file(FILE *fptr,FILE *ftemp);

int main(){

    FILE*file;
    FILE*tempFile;
    int opeation,n1,n2,flag1,flag2,result;
    int a,input,count;

    while(1){
        printf("\n1.Calculate sum/multiplication between two numbers\n");
        printf("2.Calculate prime numbers\n");
        printf("3.Show number sequence in file\n");
        printf("4.Sort number sequence in file\n");
        printf("------------------------------------------------\n");
        printf("Please select menu:");
        scanf("%d",&opeation);

        switch(opeation){
            case 1:
                printf("Please enter '0' for sum,'1' for multiplication.\n");
                scanf("%d",&flag1);
                printf("Please enter '0' to work on even numbers,'1' to work on odd numbers.\n");
                scanf("%d",&flag2);
                printf("Please enter two different number:\n");
                printf("Number 1:");
                scanf("%d",&n1);
                printf("Number 2:");
                scanf("%d",&n2);

                switch(flag1){   //Controls whether to add or multiply
                    case 0:     
                        result=sum(n1,n2,flag2);
                        printf("=%d\n",result);
                        write_file(file,result);
                        break;
                    case 1:
                        result=multi(n1,n2,flag2);
                        printf("=%d\n",result);
                        write_file(file,result);
                        break;
                    default:
                        printf("\nInvalid operation '0' for sum '1' for multi.\n\n");
                        break;
                }
                break;
            case 2:
                printf("Please enter an integer:");
                scanf("%d",&a);
                
                for(int i=2;i<a;i++){       //checks the prime of the number, if not, writes which number it is divided by
                    input=isprime(i);
                    if(input==0) printf("%d is a prime number.\n",i);
                    else printf("%d is not prime number,it is dividible by %d.\n",i,input);
                }
                break;
            case 3:
                print_file(file);//it writes numbers in the file
                printf("\n");
                break;
            case 4:
                sort_file(file,tempFile);   //function that sorts numbers in ascending order
                change_file(file,tempFile); //transfers sorted numbers from temp file to main file
                break;
        }
    }

    return 0;
}

int sum(int n1,int n2,int flag){
    int total=0,min=n1+1,max=n2,i=0,count=0;    
    if(n1>n2){
        min=n2+1;
        max=n1;
    }
    switch(flag){      //Determines whether the numbers to be added should be odd or even -even is 0/odd is 1  
        case 0:
            for(i=min;i<max;i++){
                if(i%2 == 0){
                    if(count ==0)  printf("%d",i);
                    else printf("+%d",i);
                    total+=i;
                    count++;
                }
            }break;
        case 1:
            for(i=min;i<max;i++){
                if(i%2 != 0){
                    if(count ==0)  printf("%d",i);
                    else printf("+%d",i);
                    total+=i;
                    count++;
                }
            }break;
        default:
            printf("\nInvalid operation '0' for even '1' for odd num.\n\n");break;
    }
    return total;
}

int multi(int n1,int n2,int flag){
    int total=1,min=n1+1,max=n2,i,count=0;
    if(n1>n2){
        min=n2+1;
        max=n1;
    }
    switch(flag){   //Determines whether the numbers to be added should be odd or even-even is 0/odd is 1
        case 0:
            for(i=min;i<max;i++){
                if(i%2 == 0){
                    if(count ==0)  printf("%d",i);
                    else printf("*%d",i);
                    total*=i;
                    count++;
                }
            }break;
        case 1:
            for(i=min;i<max;i++){
                if(i%2 != 0){
                    if(count ==0)  printf("%d",i);
                    else printf("*%d",i);
                    total*=i;
                    count++;
                }
            }break;
        default:
            printf("\nInvalid operation '0' for even '1' for odd num.\n\n");break;
    }
    return total;
}

int isprime(int a){     //checks the prime of the number, if not, writes which number it is divided by
    int r=0;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i == 0){
            r=i;
            break;
        }
    }
    return r;
}

void write_file(FILE *fptr,int number){//The function of printing the numbers we get from the operations to the file
    fptr = fopen("results.txt","a");
    if(fptr == NULL) printf("File cannot open!\n");

    fprintf(fptr," %d",number);
    fclose(fptr);
    printf("The result is written to the results.txt file.\n");
}

void print_file(FILE *fptr){//prints the numbers in the file to the screen
    int num;
    fptr = fopen("results.txt","r");
    if(fptr == NULL){
        printf("File cannot open!\n");
    }
    printf("Result:\n");
    while (!feof(fptr)){
        fscanf(fptr,"%d",&num);
        printf("%d ",num);
    }
    fclose(fptr);
}

int numbers_count(FILE *fptr){ //it calculate how many num valid in the file
    int num,count=0;
    fptr = fopen("results.txt","r");
    if(fptr == NULL) printf("File cannot open!\n");
    while (!feof(fptr)){
        fscanf(fptr,"%d",&num);
        count++;
    }
    fclose(fptr);
    return count;
}

void sort_file(FILE *fptr,FILE *ftemp){//function that sorts numbers in ascending order
    int temp,num,i,j,k;
    int min1=0,min2=0,min3=0;

    int count = numbers_count(fptr);
    if(count%3==0) k=count/3;
    else k=count/3+1;
    ftemp=fopen("tempFile.txt","w");
    fclose(ftemp); 
    for(j=0;j<k;j++){
        for(i=0;i<3;i++){
            fptr = fopen("results.txt","r");
            if(fptr == NULL){
                printf("File cannot open!");
            }
            temp=999999999;
            while(!feof(fptr)){
                fscanf(fptr,"%d",&num);
                if(temp>num && num != min1 && num != min2 && num != min3 && num>min3){
                    temp=num;
                }
            }
            if(i==0) min1=temp;
            if(i==1) min2=temp;
            if(i==2) min3=temp;
            fclose(fptr);
        }
        ftemp=fopen("tempFile.txt","a");
        if(ftemp == NULL) printf("File cannot open!");
        if(count/3>=1){
            fprintf(ftemp,"%d %d %d ",min1,min2,min3);
            count-=3;
        }
        else if(count==2){
            fprintf(ftemp," %d %d",min1,min2);
        }
        else{
            fprintf(ftemp," %d",min1);
        }
        fclose(ftemp); 
    } 
}

void change_file(FILE *fptr,FILE *ftemp){//transfers sorted numbers from temp file to main file
    int number;
    printf("Results:\n");
    ftemp=fopen("tempFile.txt","r");
    fptr=fopen("results.txt","w");
    while(!feof(ftemp)){
       fscanf(ftemp,"%d",&number);
       fprintf(fptr,"%d ",number);
       printf("%d ",number);
    }
    fclose(ftemp);
    fclose(fptr);
}