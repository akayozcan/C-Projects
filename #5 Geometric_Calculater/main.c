#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

typedef enum shape{Exit,Triangle,Quadrilateral,Circle,Pyramid,Cylinder}Shapes;
typedef enum calculator{Area=1,Perimeter,Volume}Calculators;

int select_shape(int flag1);//get the shape selection
int select_calc(int flag2);//get calculate selection
int calc_triangle(int flag);
int calc_quadrilateral(int flag);
int calc_circle(int flag);
int calc_pyramid(int flag);
int calc_cylinder(int flag);
void clean_stdin(void);//clear input buffer
int isTriangle(int a,int b,int c);//controls whether to form a triangle based on the entered sides
int calculate(int (*select_shape)(int flag1),int (*select_calc)(int flag2));//function to be processed

int main(){

    printf("Welcome to the geometric calculator!\n");
    calculate(&select_shape,&select_calc);//I sent the function address to the calculate function

    return 0;
}


int select_shape(int flag1){//get the shape selection
    int i=0;
    do{
        if(i!=0){
            printf("ERROR!Please enter a valid entry(0-5).\n");
            clean_stdin();//clean input
        }
        i++;
        printf("\nSelect a shape to calculate:\n");
        printf("---------------------------\n");
        printf("1.Triangle\n");
        printf("2.Quadrilateral\n");
        printf("3.Circle\n");
        printf("4.Pyramid\n");
        printf("5.Cylinder\n");
        printf("0.Exit\n");
        printf("---------------------------\n");
        printf("Input:");
    }while(scanf("%d",&flag1) !=1 || flag1<0 || flag1>5);
    return flag1;
}

int select_calc(int flag2){//get calculate selection
    int x,i=0;
    do{
        if(i!=0) printf("ERROR!Please enter a valid entry.\n");
        clean_stdin();
        printf("\nSelect Calculator:\n");
        printf("------------------\n");
        printf("1.Area:\n");
        printf("2.Perimeter\n");
        printf("3.Volume\n");
        printf("0.Exit\n");
        printf("------------------\n");
        printf("Input:");
        x=scanf("%d",&flag2);
        i++;
    }while(x!=1 || flag2<0 || flag2>3);
    return flag2;
}

int calc_triangle(int flag){//Function that calculates area, perimeter and volume of triangle according to the selected calculation type
    float a,b,c,s;
    float A,P;

    if(flag != Volume && flag != Exit){
        while(1){ 
            clean_stdin(); 
            printf("\nPlease enter three sides of Triangle:\n");//Checks the correctness of the entered edge values
            if(scanf("%f",&a) !=1 || a<=0) printf("ERROR!Please enter a valid entry.\n");
            else if(scanf("%f",&b) != 1 || b<=0) printf("ERROR!Please enter a valid entry.\n");
            else if(scanf("%f",&c) !=1 || c<=0) printf("ERROR!Please enter a valid entry.\n");
            else if(isTriangle(a,b,c)==0) printf("ERROR!Please enter a valid Triangle.\n");
            else break;
        }
        s=(a+b+c)/2;
        A=sqrt(s*(s-a)*(s-b)*(s-c));//calculate area
        P=a+b+c;//calculate perimeter
    }
    switch(flag){
        case Area:
            printf("Area of Triangle:%.2f\n",A);
            break;
        case Perimeter:
            printf("Perimeter of Triangle:%.2f\n",P);
            break;
        case Volume:
            printf("ERROR! You cannot calculate the volume of a triangle.Please try again.\n");
            break;
        case Exit:
            break;
    }
}

int calc_quadrilateral(int flag){//Function that calculates area, perimeter and volume of quadrilateral according to the selected calculation type
    float a,b,c,d,s;
    float A,P;

    if(flag != Volume && flag !=Exit){
        while(1){//returns until the condition is met
            clean_stdin();  
            printf("\nPlease enter four sides of Quadrilateral:\n");//Checks the correctness of the entered edge values
            if(scanf("%f",&a) !=1 || a<=0) printf("ERROR!Please enter a valid entry.\n");
            else if(scanf("%f",&b) !=1 || b<=0) printf("ERROR!Please enter a valid entry.\n");
            else if(scanf("%f",&c) !=1 || c<=0) printf("ERROR!Please enter a valid entry.\n");
            else if(scanf("%f",&d) !=1 || d<=0) printf("ERROR!Please enter a valid entry.\n");
            else break; 
        }
        s=(a+b+c+d)/2;
        A=sqrt((s-a)*(s-b)*(s-c)*(s-d));//calculate area
        P=a+b+c+d;//calculate perimeter
    }
    switch(flag){
        case Area:
            printf("Area of Quadrilateral:%.2f\n",A);
            break;
        case Perimeter:
            printf("Perimeter of Quadrilateral:%.2f\n",P);
            break;
        case Volume:
            printf("ERROR! You cannot calculate the volume of a quadrilateral.Please try again.\n");
            break;
        case Exit:
            break;
    }
}

int calc_circle(int flag){//Function that calculates area, perimeter and volume of circle according to the selected calculation type
    float r,A,P;

    if(flag != Volume){
        while(1){  
            clean_stdin();
            printf("\nPlease enter the radius of Circle:\n");//Checks the correctness of the entered edge values
            if(scanf("%f",&r) !=1 || r<=0) printf("ERROR!Please enter a valid entry.\n");
            else break; 
        }
        A=pi*r*r;//calculate area
        P=2*pi*r;//calculate perimeter
    }
    
    switch(flag){
        case Area:
            printf("Area of Circle:%.2f\n",A);
            break;
        case Perimeter:
            printf("Perimeter of Circle:%.2f\n",P);
            break;
        case Volume:
            printf("ERROR! You cannot calculate the volume of a circle.Please try again.\n");
            break;
        case Exit:
            break;
    }
}

int calc_pyramid(int flag){//Function that calculates area, perimeter and volume of pyramid according to the selected calculation type
    float a,h,l;
    float B,L,V;
    
    switch(flag){
        case Area:
            while(1){
                clean_stdin();  
                printf("\nPlease enter the base side and slant height of Pyramid:\n");//Checks the correctness of the entered edge values
                if(scanf("%f",&a) !=1 || a<=0) printf("ERROR!Please enter a valid entry.\n");
                else if(scanf("%f",&l) != 1 || l<=0) printf("ERROR!Please enter a valid entry.\n");
                else break;
            }
            B=a*a;//calculate base area
            L=2*a*l;//calculate lateral surface
            printf("Base Surface Area of a Pyramid:%.2f\n",B);
            printf("Lateral Surface Area of a Pyramid:%.2f\n",L);
            printf("Surface Area of a Pyramid:%.2f\n",B+L);
            break;
        case Perimeter:
            printf("Perimeter of Pyramid:%.2f\n",B);
            break;
        case Volume:
            while(1){
                clean_stdin();  
                printf("\nPlease enter the base side and height of Pyramid:\n");
                if(scanf("%f",&a) !=1 || a<=0) printf("ERROR!Please enter a valid entry.\n");
                else if(scanf("%f",&h) != 1 || h<=0) printf("ERROR!Please enter a valid entry.\n");
                else break;
            }
            V=(a*a*h)/3;//calculate volume
            printf("Volume of a Pyramid:%.2f\n",V);
            break;
        case Exit:
            break;
    }
}

int calc_cylinder(int flag){//Function that calculates area, perimeter and volume of cylinder according to the selected calculation type
    float r,h;
    float V,P,bA,lA,sA;
    
    while(1){
        clean_stdin();  
        printf("\nPlease enter the radius and height of Cylinder:\n");//Checks the correctness of the entered edge values
        if(scanf("%f",&r) !=1 || r<=0) printf("ERROR!Please enter a valid entry.\n");
        else if(scanf("%f",&h) !=1 || h<=0) printf("ERROR!Please enter a valid entry.\n");
        else break;
    }
    V=pi*r*r*h;//calculate volume
    P=(4*2*pi*r) + (2*h);//calculate perimeter
    bA=pi*r*r;//calculate base area
    lA=2*pi*r*h;//calculate lateral area
    sA=2*pi*r*(r+h);//calculate total surface area
    switch(flag){
        case Area:
            printf("Base Surface Area of a Cylinder:%.2f\n",bA);
            printf("Lateral Surface Area of a Cylinder:%.2f\n",lA);
            printf("Surface Area of a Cylinder:%.2f\n",sA);
            break;
        case Perimeter:
            printf("Perimeter of Cylinder:%.2f\n",P);
            break;
        case Volume:
            printf("Volume of Cylinder:%.2f\n",V);
            break;
        case Exit:
            break;
    }
}

int calculate(int (*select_shape)(int flag1),int (*select_calc)(int flag2)){
    int flag1,flag2;
    do{ 
        flag1=(*select_shape)(flag1);//function argument that selects shape from user
        switch (flag1){
            case Triangle:
                flag2 =(*select_calc)(flag2);//function argument that selects calculation type from user
                calc_triangle(flag2);
                break;

            case Quadrilateral:
                flag2 =(*select_calc)(flag2);
                calc_quadrilateral(flag2);
                break;

            case Circle:
                flag2 =(*select_calc)(flag2);
                calc_circle(flag2);
                break;

            case Pyramid:
                flag2 =(*select_calc)(flag2);
                calc_pyramid(flag2);
                break;

            case Cylinder:
                flag2 =(*select_calc)(flag2);
                calc_cylinder(flag2);
                break;
        }
    }while (flag1 != Exit);
}

int isTriangle(int a,int b,int c){
    int r=0;
    if((abs(b-c)<a && a<(b+c)) && (abs(a-c)<b && b<(a+c)) && (abs(a-b)<c && c<(a+b))) r=1;//|b-c|<a<b+c ...
    return r;
}

void clean_stdin(void){//clear input buffer
    int c;
    do {
        c = getchar();
    }while (c != '\n' && c != EOF);
}