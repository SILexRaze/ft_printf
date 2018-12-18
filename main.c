/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:26:23 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/18 15:24:42 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char	*c;
	short	a;

	a = 10;
	c = "salut";
	ft_printf("%5d\n", -42);
	printf("%5d\n", -42);
	ft_printf("@moulitest: %.10d\n", -42);
	printf("@moulitest: %.10d\n", -42);
	ft_printf("%+10.5d\n", 4242);
	printf("%+10.5d\n", 4242);
	ft_printf("%10.5d\n", 4242);
	printf("%10.5d\n", 4242);
	ft_printf("%-10.5d\n", -42);
	printf("%-10.5d\n", -42);
	ft_printf("%+05d\n", 42);
	printf("%+05d\n", 42);
	ft_printf("%3.2d\n", -1);
	printf("%3.2d\n", -1);
	ft_printf("%10.2s\n", "salut");
	printf("%10.2s\n", "salut");
	ft_printf("%10.1x\n", 255);
	printf("%10.1x\n", 255);
	ft_printf("%10.1X\n", 255);
	printf("%10.1X\n", 255);
	printf("p=%10c\n", 'v');
	ft_printf("m=%10c\n", 'v');
	printf("p%10p\n", c);
	ft_printf("m%10.5p\n", c);
	ft_printf("m=%10.5i\n", 1);
	printf("p=%10.5i\n", 1);
	ft_printf("m=%o\n", 10);
	printf("p=%o\n", 10);
	ft_printf("%50.5f\n", 14527.98723548);
	printf("%50.5f\n", 14527.98723548);
	ft_printf("m=%010d\n", -300);
	printf("p=%010hd\n", a);
	ft_printf("m=% +d\n", 300);
	printf("p=%+d\n", 300);
	printf("p=% d\n", 300);
	ft_printf("m=%hd\n", 38000);
	printf("p=%hd\n", (short)38000);
	ft_printf("m=%ld\n", (long int)123);
	printf("p=%ld\n", (long int)123);
	ft_printf("m=%d\n", (signed char)128);
	printf("p=%d\n", (signed char)128);
	ft_printf("m=%hd\n", (short int)123);
	printf("p=%hd\n", (short int)123);
	ft_printf("%.20f\n", 1.4);
	printf("%.20f\n", 1.4);
	ft_printf("%x\n", 255);
	printf("%x\n", 255);
	ft_printf("%#x\n", 255);
	printf("%#x\n", 255);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%#o\n", 255);
	printf("%#o\n", 255);
	ft_printf("%#010X\n", 255);
	printf("%#010X\n", 255);
	ft_printf("m=%.1f\n", 123.0);
	printf("p=%.1f\n", 123.0);
	ft_printf("m=@moulitest: %.10d\n", -42);
	printf("p=@moulitest: %.10d\n", -42);
	ft_printf("m=%0+5d\n", 42);
	printf("p=%0+5d\n", 42);
	ft_printf("%3c\n", 0);
	printf("%3c\n", 0);
	ft_printf("%10V\n");
	printf("%10V\n");
	ft_printf("m={% 03d}\n", 0);
	printf("p={% 03d}\n", 0);
	ft_printf("m=%.4d\n", -424242);
	printf("p=%.4d\n", -424242);
	ft_printf("m=%15.4o\n", 42);
	printf("p=%15.4o\n", 42);
	ft_printf("m=%15.4s\n", "I am 42");
	printf("p=%15.4s\n", "I am 42");
	ft_printf("m=%.0p, %.p\n", 0, 0);
	printf("p=%.0p, %.p\n", 0, 0);
	printf("test=|% -4d|\n", 10);
	printf("\nsigned int\n");
	ft_printf("% d\n", -42);
	printf("% d\n", -42);
	ft_printf("%.5d\n", 10);
	printf("%.5d\n", 10);
	ft_printf("% +.5d\n", -10);
	printf("% +.5d\n", -10);
	ft_printf("% +.1d\n", +10);
	printf("% +.1d\n", +10);
	ft_printf("%-10d\n", -12000);
	printf("%-10d\n", -12000);
	printf("\nunsigned\n");
	ft_printf("%.5u\n", 10);
	printf("%.5u\n", 10);
	ft_printf("%5u\n", 10);
	printf("%5u\n", 10);
	ft_printf("%+u\n", -10);
	printf("%u\n", -10);
	ft_printf("%+.2u\n", +10);
	printf("%+.2u\n", +10);
	ft_printf("%-10.10u\n", -12000);
	printf("%-10.10u\n", -12000);
	printf("\noctal\n");
	ft_printf("%.5o\n", 10);
	printf("%.5o\n", 10);
	ft_printf("%5o\n", 10);
	printf("%5o\n", 10);
	ft_printf("%+o\n", -10);
	printf("%o\n", -10);
	ft_printf("%+.2o\n", +10);
	printf("%+.2o\n", +10);
	ft_printf("%-10.100o\n", -12000);
	printf("%-10.100o\n", -12000);
	printf("\nfloat\n");
	ft_printf("%.15f\n", 10.123);
	printf("%.15f\n", 10.123);
	ft_printf("%5f\n", 0.123456789);
	printf("%5f\n", 0.123456789);
	ft_printf("%+f\n", 0.0);
	printf("%+f\n", 0.0);
	ft_printf("%+.0f\n", 10.0);
	printf("%+.0f\n", 10.0);
	ft_printf("%-10.100f\n", -12000.0);
	printf("%-10.100f\n", -12000.0);
	printf("\nminhex\n");
	ft_printf("%#-10x\n", 10);
	printf("%#-10x\n", 10);
	ft_printf("% 5x\n", 10);
	printf("% 5x\n", 10);
	ft_printf("%+x\n", -10);
	printf("%x\n", -10);
	ft_printf("%+.2x\n", +10);
	printf("%+.2x\n", +10);
	ft_printf("% -10.100x\n", -12000);
	printf("% -10.100x\n", -12000);
	printf("\nmaxhex\n");
	ft_printf("%#-10X\n", 10);
	printf("%#-10X\n", 10);
	ft_printf("% 5X\n", 10);
	printf("% 5X\n", 10);
	ft_printf("%+X\n", -10);
	printf("%X\n", -10);
	ft_printf("%+.2X\n", +10);
	printf("%+.2X\n", +10);
	ft_printf("% -10.100X\n", -12000);
	printf("% -10.100X\n", -12000);
	ft_printf("m=%lld\n", -9223372036854775808);
	printf("p=%lld\n", -9223372036854775808);
	ft_printf("m=%#o\n", 0);
	printf("p=%#o\n", 0);
	ft_printf("m=%.0p, %.p\n", 0, 0);
	printf("p=%.0p, %.p\n", 0, 0);
	ft_printf("m=%.5p\n", 0);
	printf("p=%.5p\n", 0);
	ft_printf("m=%#.o, %#.0o\n", 0, 0);
	printf("p=%#.o, %#.0o\n", 0, 0);
	ft_printf("m=%.o, %.0o\n", 0, 0);
	printf("p=%.o, %.0o\n", 0, 0);
	ft_printf("m={%05.c}\n", 0);
	printf("p={%05.c}\n", 0);
	ft_printf("%p\n", 1234);
	printf("%p\n", 1234);
	ft_printf("%9.2p\n", 1234);
	printf("%9.2p\n", 1234);
	ft_printf("%9.2p\n", 1234);
	printf("%9.2p\n", 1234);
	ft_printf("%9.2p\n", 1234567);
	printf("%9.2p\n", 1234567);
	ft_printf("%2.9p\n", 1234567);
	printf("%2.9p\n", 1234567);
	ft_printf("%lu\n", (unsigned long)-42);
	printf("%lu\n", (unsigned long)-42);
	ft_printf("%.15s\n", "coco");
	printf("%.15s\n", "coco");
	ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	ft_printf("m=%f\n", -1.4);
	printf("p=%f\n", -1.4);
	
	return (0);
}
