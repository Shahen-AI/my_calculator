#include "my_calc.h"

int main(int argc, char **argv)
{
	char *str;

	str = symb_check(argc, argv);
	if (!str)
		return(1);
	printf("The answer is : %f\n", calc(str));
	return (0);
}