#include "my_calc.h"

int helper(int argc, char **argv, t_fd create_fd, MYSQL	*con)
{
	int		bracket = 0;
	char	*str;
	double	result;
	char	*temp;
	char	*str_temp;

	str = symb_check(argc, argv, &bracket, create_fd);
	if (!str)
		return(-1);
	creating_table(con, str);
	str_temp = ft_strjoin(str, "");
	str = get_from_db(con);
	if (!bracket)
		result = calc(str);
	else
		result = br_calc(str);
	inserting_table(con, str_temp, (int)result);
	result = insert_from_db(con);
	if (create_fd.fd)
	{
		temp = ft_itoa((int)result);
		write(create_fd.fd, "The answer is : ", 16);
		write(create_fd.fd, temp, ft_strlen(temp));
		write(create_fd.fd, "\n", 1);
	}
	else
		printf("The answer is : %f\n", result);
	printf("Check all expressions and answers in \"calcDB\" database!\n");
	return (0);
}

int main(int argc, char **argv)
{
	char 	*str;
	int		fd;
	int		a;
	int		i;
	double	returnVAL;
	t_fd	create_fd;
	MYSQL	*con;

	con = mysql_init(NULL);
	fd = open(argv[1], 0666);
	if (fd > 0)
	{
		a = 1;
		create_fd.fd = open("Answers", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		while (a)
		{
			a = get_next_line(fd, &create_fd.fd_str);
			i = -1;
			while (is_space(create_fd.fd_str[++i]));
			if (create_fd.fd_str[i] != '\0')
				helper(argc, argv, create_fd, con);
		}
		close(create_fd.fd);
		printf("See your answers in file \"Answers\"\n");
	}
	else
	{
		create_fd.fd = 0;
		helper(argc, argv, create_fd, con);
	}
	close(fd);
	mysql_close(con);
	return (0);
}