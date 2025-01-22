/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:12:53 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/10 11:26:15 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

void	ft_putstr(char *str, int *result)
{
	if (str == NULL)
		ft_putstr("(null)", result);
	else
	{
		while (*str)
		{
			ft_putchar(*str, result);
			str++;
		}
	}
}

void	check_condition(const char *format, va_list ap, int *result)
{
	if (format[1] == 'c')
		ft_putchar(va_arg(ap, int), result);
	if (format[1] == 's')
		ft_putstr(va_arg(ap, char *), result);
	if (format[1] == 'p')
		ft_putadd(va_arg(ap, void *), result);
	if (format[1] == 'd' || format[1] == 'i')
		ft_putnum(va_arg(ap, int), result);
	if (format[1] == 'u')
		ft_put_unum(va_arg(ap, unsigned int), result);
	if (format[1] == 'x' || format[1] == 'X')
		ft_puthex(va_arg(ap, unsigned int), result, format[1]);
	if (format[1] == '%')
		ft_putchar('%', result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			check_condition(format, ap, &result);
			format++;
		}
		else
			ft_putchar(*format, &result);
		format++;
	}
	va_end(ap);
	return (result);
}

/* #include <stdio.h>

int	main(void)
{
	int				count_p;
	int				count_ft;
	int				a;
	unsigned int	u;
	char			*s = NULL;

	ft_printf("-------%%c--------\n");
	printf("-------%%c--------\n");
	count_ft = ft_printf("ft_printf : %c%c%c\n", 'a', 'P', '\0');
	count_p = printf("   printf : %c%c%c\n", 'a', 'P', '\0');
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("\n-------%%s--------\n");
	printf("-------%%s--------\n");
	count_ft = ft_printf("ft_printf : %s %s\n", s, "lalalalala");
	count_p = printf("   printf : %s %s\n", s, "lalalalala");
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("\n-------%%d--------\n");
	printf("-------%%d--------\n");
	a = -2147483648;
	count_ft = ft_printf("ft_printf : %d %d %d\n", 0, a, 2147483647);
	count_p = printf("   printf : %d %d %d\n", 0, a, 2147483647);
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("\n-------%%i--------\n");
	printf("-------%%i--------\n");
	count_ft = ft_printf("ft_printf : %i %i %i\n", 0, a, 2147483647);
	count_p = printf("   printf : %i %i %i\n", 0, a, 2147483647);
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("\n-------%%u--------\n");
	printf("-------%%u--------\n");
	u = 4294967295;
	count_ft = ft_printf("ft_printf : %u %u\n", 0, u);
	count_p = printf("   printf : %u %u\n", 0, u);
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);
	
	ft_printf("\n-------%%x--------\n");
	printf("-------%%x--------\n");
	count_ft = ft_printf("ft_printf : %x %x %x\n", 0, u, 123456789);
	count_p = printf("   printf : %x %x %x\n", 0, u, 123456789);
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("\n-------%%X--------\n");
	printf("-------%%X--------\n");
	count_ft = ft_printf("ft_printf : %X %X %X\n", 0, u, 123456789);
	count_p = printf("   printf : %X %X %X\n", 0, u, 123456789);
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("\n-------%%p--------\n");
	printf("-------%%p--------\n");
	a = 0;
	count_ft = ft_printf("ft_printf : %p %p %p\n", &a, &u, &s);
	count_p = printf("   printf : %p %p %p\n", &a, &u, &s);
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);
	count_ft = ft_printf("%p %p \n", (void *)0, (void *)0);
	count_p = printf("%p %p \n", (void *)0, (void *)0);
	ft_printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	return (0);
}
 */