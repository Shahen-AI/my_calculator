#include "my_calc.h"

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
