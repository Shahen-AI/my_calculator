#include "my_calc.h"

double br_calc(char *str)
{
	int i = -1, len;
	int bracket_count = 0;
	char *temp;

	while (str[++i])
		if (str[i] == '(')
			++bracket_count;
	while (bracket_count-- > 0)
	{
		i = -1;
		len = 0;
		while (str[++i] != ')');
		while (str[i - len] != '(')
			++len;
		str[i] = ' ';
		str[i - len] = ' ';
		temp = malloc(sizeof(temp) * len);
		for (int j = 0; j < len - 1; ++j)
			temp[j] = str[i - len + j + 1];
		temp[len - 1] = '\0';
		temp = ft_itoa((int)calc(temp));
		for (int j = 0; j < ft_strlen(temp); ++j)
			str[i - len + j] = temp[j];
		int k = ft_strlen(temp);
		while (i - len + k != i)
		{
			str[i - len + k] = ' ';
			++k;
		}
		free(temp);
	}
	return(calc(str));
}

double calc(char *str)
{
	int mal_size = 1, i = -1, k, once = 0;
	int checker = 0;
	double result = 0;
	double *nums;
	char *signs;

	while (str[++i])
		if (is_valid(str[i], 1))
			++mal_size;
	nums = malloc(sizeof(int *) * mal_size);
	signs = malloc(sizeof(char *) * mal_size);
	signs[mal_size] = '\0';
	i = -1;
	k = 0;
	while (is_space(str[++i]));
	if (str[i] == '-')
	{
		k = 1;
		++once;
	}
	for (int j = 0; j < mal_size; ++j)
		nums[j] = 0;
	i = 0;
	while (str[i])
	{
		if (is_num(str[i]))
			nums[k] = nums[k] * 10 + (str[i] - '0');
		if (is_valid(str[i], 1))
		{
			if (signs[k] == '-' && signs[k - 1] == '*')
				nums[k] *= -1;
			signs[k] = str[i];
			if (signs[k] == '-' && signs[k - 1] == '*')
				--k;
			++k;
		}
		if (once == 1)
		{
			++once;
			--k;
		}
		++i;
	}
	if (once == 2)
		signs[0] = '-';
	for (int j = 0; j < mal_size; ++j)
	{
		if (signs[j] == '-')
			nums[j + 1] *= -1;
	}
	if (once == 0)
		--mal_size;
	int temp, jk = 0;
	i = 0;
	while (jk < mal_size)
	{
		temp = jk + 1;
		while (signs[jk] == '*' || signs[jk] == '/')
		{
			if (signs[temp - 1] == '*')
			{
				nums[jk] = nums[jk] * nums[temp];
				nums[temp] = 0;
			}
			else
			{
				nums[jk] = nums[jk] / nums[temp];
				nums[temp] = 0;
			}
			++temp;
			if (signs[temp - 1] != '/' && signs[temp - 1] != '*')
				break ;
		}
		for (int j = 0; j < jk; j++)
			signs[j] = '+';
		jk = temp;
	}
	if (once == 0)
		++mal_size;
	for (int j = 0; j < mal_size; ++j)
		result += nums[j];
	free(nums);
	free(signs);
	return (result);
}
