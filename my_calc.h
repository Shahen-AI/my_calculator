#ifndef MY_CALC_H
#define MY_CALC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <mysql/mysql.h>
#include "get_next_line/get_next_line.h"

typedef struct s_fd
{
    int     fd;
    char    *fd_str;
}           t_fd;

int		is_num(char a);
int		is_space(char a);
int		is_bracket(char a);
int		ft_strlen(char *str);
int		is_valid(char a, int check);
int     ft_atoi(const char *nptr);
int     insert_from_db(MYSQL	*con);
char	*ft_itoa(int n);
char	*printer(char *str, int fd);
char	*symb_check(int argc, char **argv, int *br_check, t_fd create_fd);
char    *get_from_db(MYSQL	*con);
void    finish_with_error(MYSQL *con);
void    creating_table(MYSQL	*con, char *arg);
void    inserting_table(MYSQL	*con, char *arg, int val);
double	calc(char *str);
double	br_calc(char *str);

#endif