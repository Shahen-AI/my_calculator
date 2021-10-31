#include "my_calc.h"

int main(int argc, char **argv)
{
	char 	*str;
	int		bracket = 0;
	int		fd;
	char	*BUFFER;
	
	fd = open(argv[1], 0666);
	if (fd > 0)
	{
		// printf("here /%s/\n", argv[1]);
		
		read(fd, BUFFER, ft_strlen(argv[1]));
		return (0);
	}
	else
		str = symb_check(argc, argv, &bracket);
	if (!str)
		return(1);
	if (!bracket)
		printf("The answer is : %f\n", calc(str));
	else
		printf("The answer is : %f\n", br_calc(str));
	return (0);
}