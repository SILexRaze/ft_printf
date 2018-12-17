#include "ft_printf.h"
#include <stdio.h>

#define ULONG_MAX 18446744073709551615

int	main()
{
	unsigned long  max = ULONG_MAX;
	unsigned long min = 0;
/*	printf("format%%lx, %%lx, 0, ULONG_MAX)\n");
	ft_printf("m=%lx, %lx\n", min, max);
	printf("p=%lx, %lx\n\n", min, max);
	
	printf("format%%lo, %%lo, 0, ULONG_MAX)\n");
	ft_printf("m=%lo, %lo\n", min, max);
	printf("p=%lo, %lo\n\n", min, max);

	printf("autre valeur max oxX longmax llmax\n\n");
	printf("tout le test 43\n\n");
	
	printf("format={%%05p}\n");
	ft_printf("m={%05p}\n", 0);
	printf("p={%05p}\n\n", 0);*/

	printf("format={%% 03d}\n");
	ft_printf("m={% 03d}\n", 0);
	printf("p={% 03d}\n\n", 0);
	
	ft_printf("m=%.4d\n", -424242);
	printf("p=%.4d\n", -424242);

	printf("regarder test 70 a 79\n");
}
