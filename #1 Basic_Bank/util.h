#ifndef _UTIL_H_
#define _UTIL_H_

#define ID 11

int find_divisible(int x, int y, int z);
int find_nth_divisible(int n, int f_I, int z);
int validate_identity_number(char identity_number[ID]);
int create_customer(char identity_number[ID], int password);
int check_login(char identity_number[ID], int password);
int withdrawable_amount(float cash_amount);

#endif /* _UTIL_H_ */