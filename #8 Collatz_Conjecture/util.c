#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void generate_sequence (int xs, int currentlen, int seqlen, int *seq){//If the number is odd,it is 3x+1,if it is even number,x/2 is applied to obtain array
									//The array is filled to the size given by the user.
    if(xs%2==0){
        seq[currentlen]=xs;
        xs/=2;
    }
    else{
        seq[currentlen]=xs;
        xs=3*xs+1;
    }
    if(currentlen<seqlen) generate_sequence(xs,currentlen+1,seqlen,seq);//recursive function that finds the next element of the array..
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le){//funciton taht checks whether there is a loop in the array.
    int counter=0;
    int r,i=1;
    while(i <= looplen){
        *le = n-i;
        *ls = n-looplen-i;
        if(arr[*le]!=arr[*ls]){  //CheckIF *ls and *le MATCH...

            counter++;
            break;
        }
        i++;
    }
    if(counter==0) r=1;  //If there is a loop ,it returns 1 else it returns 0;
    else r=0; 
    return r;
}

void check_loop_iterative(void (*f)(int xs,int currentlen,int seqlen,int *seq), int xs, int seqlen, int *loop,int *looplen){
    int *seq=(int*)malloc(sizeof(int)*seqlen);//dynamiclaly allocates the array...
    static int count=0;
    int ls,le,i=0,k=0;
    int check_loop;
    f(xs,0,seqlen-1,seq);//it calls generate_sequance function...
    if(count==0){
        printf("\nSequence: {");//print the sequence on the screen
        for(i=0;i<seqlen-1;i++){
            printf("%d, ",seq[i]);
        }
        printf("%d}\n\n",seq[i]);
        count++;
    }
    check_loop=has_loop(seq,seqlen,*looplen,&ls,&le);
    printf("Checking if there is a loop of length %d...\n",*looplen);
    if(check_loop==1){//if the value from the has_loop is 1 printt every info on the screen,looplen-loop array...
        for(i=ls;i<le;i++){
            loop[k]=seq[i];
            k++;
        }
       
        printf("\nLoop detected with a length of %d.\n",*looplen);
        printf("The indexes of the loop's first occurance: %d (first digit) %d (last digit)",ls,le-1);
        printf("\nLoop: {");
        for(i=0;i<*looplen-1;i++){
            printf("%d, ",loop[i]);
        }
        printf("%d}\n",loop[i]);
    }
    else if(check_loop==0 && *looplen>2){//if the loop isn t found,the search continues from n/2 to 2.
        *(looplen)-=1;
        check_loop_iterative(generate_sequence,xs,seqlen,loop,looplen);
    }
    else{
        printf("No loop found\n");
    }
}

void hist_of_firstdigits(void (*f)(int xs,int currentlen,int seqlen,int *seq), int xs, int seqlen, int *h, int digit){
    static int current_lenn = 0;
    int i=0;
    int count=0;

    f(xs,0,seqlen-1,h);//it calls generate_sequance function...

    for(i=0;i<seqlen;i++){
        while(h[i]>=10){
            h[i]=h[i]/10;
        }    
        if(h[i]==digit) count++;//Takes the first digit of the elements in the arrray and finds how many there are from 1 to 9 
    }
    h[seqlen+current_lenn]=count;
    current_lenn+=1;
    if(digit<=9) return hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit+1);
}
