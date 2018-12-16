#include "ft_printf.h"
#include <stdio.h>

#define ULONG_MAX 18446744073709551615

int	main()
{
	unsigned long  max = ULONG_MAX;
	unsigned long min = 0;
	printf("format%%lx, %%lx, 0, ULONG_MAX)\n");
	ft_printf("%lx, %lx\n", min, max);
	printf("%lx, %lx\n\n", min, max);
	
	printf("format%%lo, %%lo, 0, ULONG_MAX)\n");
	ft_printf("%lo, %lo\n", min, max);
	printf("%lo, %lo\n\n", min, max);

	printf("autre valeur max oxX longmax llmax\n\n");
	printf("tout le test 43\n\n");
	
	printf("format={%%05p}\n");
	ft_printf("{%05p}\n", 0);
	printf("{%05p}\n\n", 0);

	printf("format={%% 03d}\n");
	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n\n", 0);
	
	printf("regarder test 70 a 79\n");
}
