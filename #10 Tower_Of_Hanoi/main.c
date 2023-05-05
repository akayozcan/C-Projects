#include <stdio.h>
#include <stdlib.h>

#define STACK_BLOCK_SIZE 10

typedef struct 
{
    int * array;
    int currentsize;
    int maxsize;
}Stack;


int push(Stack *s,int d){
    int x=s->currentsize;
    if(s->currentsize >= STACK_BLOCK_SIZE){//Dynamically doubles the capacity of the stack array,if it is full
        Stack *temp;
        temp->array=(int*)malloc(sizeof(int)*s->maxsize*2);//ı creat temp variable to copy new array to old one
        temp->maxsize=s->maxsize*2;
        for(int i=0;i<s->currentsize;i++){//Copying to contents of the previous array to the new array...
            temp->array[i]=s->array[i];
        }
        free(s);//free the old stack
        s=temp;
        printf("İncreasing of size has been complited!\n");
    }
    s->array[x]=d;
    s->currentsize++;
}

void pop (Stack*s);

Stack *init_return(Stack * init_hole){//I initilazed  to the size of the stack arrays to be 10
    init_hole->array=(int*)malloc(sizeof(int)*STACK_BLOCK_SIZE);
    printf("Empty stack initilazed...\n");
    return init_hole;
}
int init(Stack *s);


int main(){

    Stack *hole1;
    Stack *hole2;
    Stack *hole3;
    hole1=hole2=hole3 = (Stack*)malloc(sizeof(Stack));

    hole1->currentsize=0;
    hole1->maxsize=STACK_BLOCK_SIZE;
    hole1=init_return(hole1);
    hole2=init_return(hole2);
    hole3=init_return(hole3);

    push(hole1,10);
    push(hole1,20);
    push(hole1,30);
    push(hole1,40);
    push(hole1,50);
    push(hole1,10);
    push(hole1,20);
    push(hole1,30);
    push(hole1,40);
    push(hole1,50);

    for(int i=0;i<10;i++){
        printf("%d ",hole1->array[i]);
    }
    printf("\n");

    return 0;
}