#ifndef MY_CALC_H
#define MY_CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"

int		is_num(char a);
int		is_space(char a);
int		is_bracket(char a);
int		ft_strlen(char *str);
int		is_valid(char a, int check);
char	*ft_itoa(int n);
char	*printer(char *str, char *fd);
char	*symb_check(int argc, char **argv, int *br_check, char *fd);
double	calc(char *str);
double	br_calc(char *str);

#endif