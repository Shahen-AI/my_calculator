#include "my_calc.h"

int helper(int argc, char **argv, t_fd create_fd)
{
	int		bracket = 0;
	char	*str;
	double	result;
	char	*temp;

	str = symb_check(argc, argv, &bracket, create_fd);
	if (!str)
		return(1);
	if (!bracket)
		result = calc(str);
	else
		result = br_calc(str);
	if (create_fd.fd)
	{
		temp = ft_itoa((int)result);
		write(create_fd.fd, "The answer is : ", 16);
		write(create_fd.fd, temp, ft_strlen(temp));
		write(create_fd.fd, "\n", 1);
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
	t_fd	create_fd;
	
	fd = open(argv[1], 0666);
	if (fd > 0)
	{
		a = 1;
		create_fd.fd = open("Answers", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		while (a)
		{
			a = get_next_line(fd, &create_fd.fd_str);
			helper(argc, argv, create_fd);
		}
		close(create_fd.fd);
		printf("See your answers in file \"Answers\"\n");
	}
	else
	{
		create_fd.fd = 0;
		helper(argc, argv, create_fd);
	}
	close(fd);
	return (0);
}