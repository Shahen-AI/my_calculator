#ifndef MY_CALC_H
#define MY_CALC_H

#include <stdio.h>
#include <stdlib.h>

int		is_num(char a);
int		is_space(char a);
int		is_bracket(char a);
int		ft_strlen(char *str);
int		is_valid(char a, int check);
char	*printer(char *str, int fail);
char	*symb_check(int argc, char **argv, int *br_check);
double	calc(char *str);
double	br_calc(char *str);

#endif