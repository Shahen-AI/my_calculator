#include "my_calc.h"

int helper(int argc, char **argv, char *fd, int fd_check)
{
	int		bracket = 0;
	char	*str;
	double	result;
	char	*temp;

	str = symb_check(argc, argv, &bracket, fd);
	if (!str)
		return(1);
	if (!bracket)
		result = calc(str);
	else
		result = br_calc(str);
	if (fd_check)
	{
		temp = ft_itoa((int)result);
		write(fd_check, "The answer is : ", 16);
		write(fd_check, temp, ft_strlen(temp));
		write(fd_check, "\n", 1);
	}
	else
		printf("The answer is : %f\n", result);
	return (0);
}

int main(int argc, char **argv)
{
	char 	*str;
	int		fd;
	int		a;
	
	fd = open(argv[1], 0666);
	if (fd > 0)
	{
		a = 1;
		int op = open("Answers", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		while (a)
		{
			a = get_next_line(fd, &str);
			helper(argc, argv, str, op);
		}
		close(op);
		printf("See your answers in file \"Answers\"\n");
	}
	else
		helper(argc, argv, NULL, 0);
	close(fd);
	return (0);
}