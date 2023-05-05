#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){

    int *seq;
    int *h;
    int ls,le,looplen;
    int seqlen,first_element,i;

    printf("Please enter the sequence length:");
    scanf("%d",&seqlen);
    printf("Please enter the first element:");
    scanf("%d",&first_element);

    seq=(int*)malloc(sizeof(int)*seqlen);
    
    looplen=seqlen/2;
    check_loop_iterative(generate_sequence,first_element,seqlen,seq,&looplen);
    
    hist_of_firstdigits(generate_sequence,first_element,seqlen,h,1);
   
    
    printf("\nHistogram of the sequence: {");
    for(i=seqlen;i<seqlen+8;i++){
        printf("%d, ",h[i]);
    }
    printf("%d}\n\n",h[i]);

    return 0;
}
