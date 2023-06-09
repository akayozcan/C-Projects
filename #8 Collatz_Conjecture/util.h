#ifndef _UTIL_H_
#define _UTIL_H_

void generate_sequence (int xs, int currentlen, int seqlen, int *seq);
int has_loop(int *arr, int n, int looplen, int *ls, int *le);
void check_loop_iterative(void (*f)(int xs,int currentlen,int seqlen,int *seq), int xs, int seqlen, int *loop,int *looplen);
void hist_of_firstdigits(void (*f)(int xs,int currentlen,int seqlen,int *seq), int xs, int seqlen, int *h, int digit);

#endif /* _UTIL_H_ */
