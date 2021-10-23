#include <stdio.h>
#include <stdlib.h>

int printer(char *str, int fail)
{
	printf("%s\n", str);
	return (fail);
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

int symb_check(int argc, char **argv)
{
	int i = 0, j, len = ft_strlen(argv[1]);

	if (argc > 2)
		return (printer("Error : Too many arguments.", 1));
	if (argc == 1)
		return (printer("Error : Please enter an argument.", 1));
	if (is_valid(argv[1][len - 1], 1) || is_valid(argv[1][0], 0))
		return (printer("Error : There is some shit too.", 1));
	while (is_space(argv[1][--len]))
		if (is_valid(argv[1][len - 1], 1))
			return (printer("Error : There is some shit tooo.", 1));
	while (i < ft_strlen(argv[1]))
	{
		if (!is_valid(argv[1][i], 1) && !is_num(argv[1][i]) && !is_space(argv[1][i]))
			return (printer("Error : There is some invalid characters.", 1));
		if (is_valid(argv[1][i], 1) && i != 0)
		{
			j = i - 1;
			while (!is_valid(argv[1][j], 1) && j >= 0)
			{
				if (is_num(argv[1][j]))
				{
					j = -2;
					break ;
				}
				--j;
			}
			if (j != -2 && j != -1)
				return (printer("Error : There is some shit.", 1));
		}
		++i;
	}
	i = -1;
	while (is_space(argv[1][++i]))
		if (is_valid(argv[1][i + 1], 0))
			return (printer("Error : There is some shit too.", 1));
	return (0);
}

int calc(char *str)
{
	int result = 0, mal_size = 1, i = -1, k, once = 0, end;
	int *nums;
	char *signs;

	while (str[++i])
		if (is_valid(str[i], 1))
			++mal_size;
	i = -1;
	while (is_space(str[++i]));
	if (str[i] == '-')
		--mal_size;
	nums = malloc(sizeof(int *) * mal_size);
	signs = malloc(sizeof(char *) * mal_size + 2);
	signs[0] = '+';
	signs[mal_size + 1] = '\0';
	i = 0;
	k = 0;
	for (int j = 0; j < mal_size; ++j)
		nums[j] = 0;
	while (str[i])
	{
		if (!once && str[i] == '-')
		{
			++once;
			signs[0] = '-';
			++i;
		}
		if (is_num(str[i]))
			nums[k] = nums[k] * 10 + (str[i] - '0');
		if (is_valid(str[i], 1))
		{
			++k;
			signs[k] = str[i];
		}
		++i;
	}
	i = 1;
	end = 0;
	while (end < mal_size)
	{
		if (signs[i] == '*')
		{
			result += nums[i - 1] * nums[i];
			++end;
		}
		if (signs[i] == '/')
		{
			result += nums[i - 1] / nums[i];
			++end;
		}
		++i;
	}
	// for (int j = 0; j < mal_size; ++j)
	// {
	// 	printf("%c, ", signs[j]);
	// }
	// printf("\n");
	// for (int j = 0; j < mal_size; ++j)
	// {
	// 	printf("%d, ", nums[j]);
	// }
	// printf("\n");
	return (result);
}

int main(int argc, char **argv)
{
	if (symb_check(argc, argv))
		return(1);
	printf("The answer is : %d\n", calc(argv[1]));
	return (0);
}