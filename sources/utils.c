#include "../my_calc.h"

char *printer(char *str, int fd)
{
	if (!fd)
		printf("%s\n", str);
	else
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
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

int	ft_atoi(const char *nptr)
{
	int		i;
	int		positive;
	long	sum;

	i = 0;
	sum = 0;
	positive = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		++i;
	if (nptr[i] == '+')
		++i;
	else if (nptr[i] == '-')
	{
		positive *= -1;
		++i;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		sum = (sum * 10) + (nptr[i] - '0');
		++i;
	}
	return (positive * sum);
}

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}
