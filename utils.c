#include "my_calc.h"

char *printer(char *str, int fail)
{
	printf("%s\n", str);
	// if (!fail)
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

int is_bracket(char a)
{
	if (a == '(' || a == ')')
		return (1);
	return (0);
}

static int	int_len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
	{
		++len;
		n *= (-1);
	}
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= (-1);
	}
	else if (nbr == 0)
		res[0] = '0';
	res[len] = '\0';
	while (len > 0 && nbr != 0)
	{
		--len;
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
