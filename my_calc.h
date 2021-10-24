#ifndef MY_CALC_H
#define MY_CALC_H

#include <stdio.h>
#include <stdlib.h>

int     printer(char *str, int fail);
int     is_num(char a);
int     is_space(char a);
int     ft_strlen(char *str);
int     is_valid(char a, int check);
int     symb_check(int argc, char **argv);
double  calc(char *str);

#endif