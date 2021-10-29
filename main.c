#include "my_calc.h"

int main(int argc, char **argv)
{
	char 	*str;
	int		bracket = 0;

	str = symb_check(argc, argv, &bracket);
	if (!str)
		return(1);
	if (!bracket)
		printf("The answer is : %f\n", calc(str));
	else
		printf("The answer is : %f\n", br_calc(str));
	return (0);
}