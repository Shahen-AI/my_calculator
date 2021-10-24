#include "my_calc.h"

int main(int argc, char **argv)
{
	if (symb_check(argc, argv))
		return(1);
	printf("The answer is : %f\n", calc(argv[1]));
	return (0);
}