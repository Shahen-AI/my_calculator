#include "my_calc.h"

char *printer(char *str, int fail)
{
	printf("%s\n", str);
	if (!fail)
	return (NULL);
}

int is_num(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int is_space(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	return (0);
}

int ft_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len])
		++len;
	return (len);
}

int is_valid(char a, int check)
{
	if (check == 1)
	{
		if (a == '+' || a == '-' || a == '*' || a == '/')
			return (1);
		return (0);
	}
	else
	{
		if (a == '+' || a == '*' || a == '/')
			return (1);
		return (0);
	}
}
