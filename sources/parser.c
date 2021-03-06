#include "../my_calc.h"

char *symb_check(int argc, char **argv, int *br_check, t_fd create_fd)
{
	int i = 0, j, len;
	char *str;
	char test[100];
	int	bracket_check = 0;

	if (argc > 2)
	{
		printf("Error : Too many arguments.\n");
		return (NULL);
	}
	if (create_fd.fd)
		str = create_fd.fd_str;
	else
	{
		if (argc == 1)
		{
			printf("Enter the math expression : ");
			scanf("%s", test);
			str = malloc(sizeof(str) * ft_strlen(test) + 1);
			for (int x = 0; x < ft_strlen(test); ++x)
				str[x] = test[x];
			str[ft_strlen(test)] = '\0';
		}
		else
			str = argv[1];
	}
	len = ft_strlen(str);
	if (is_valid(str[len - 1], 1) || is_valid(str[0], 0))
		return (printer("Error : Invalid math expression.", create_fd.fd));
	while (is_space(str[--len]))
		if (is_valid(str[len - 1], 1))
			return (printer("Error : Invalid math expression.", create_fd.fd));
	while (i < ft_strlen(str))
	{
		if (!is_valid(str[i], 1) && !is_num(str[i]) && !is_space(str[i]) && !is_bracket(str[i]))
			return (printer("Error : There is invalid characters in the expression.", create_fd.fd));
		if (is_bracket(str[i]))
		{
			*br_check = 1;
			if (str[i] == '(')
				++bracket_check;
			else
				--bracket_check;
			if (bracket_check < 0)
				return (printer("Error : Invalid math expression.", create_fd.fd));
		}
		if (is_valid(str[i], 1) && i != 0)
		{
			j = i - 1;
			while (!is_valid(str[j], 1) && j >= 0)
			{
				if (is_num(str[j]))
				{
					j = -2;
					break ;
				}
				--j;
			}
			if (j != -2 && j != -1)
				return (printer("Error : Invalid math expression.", create_fd.fd));
		}
		++i;
	}
	if (bracket_check != 0)
		return (printer("Error : Invalid math expression.", create_fd.fd));
	i = -1;
	while (is_space(str[++i]))
		if (is_valid(str[i + 1], 0))
			return (printer("Error : Invalid math expression.", create_fd.fd));
	return (str);
}
