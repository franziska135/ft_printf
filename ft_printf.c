/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:40:36 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/20 10:40:38 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found(char c)
{
	if (c == 's' || c == '%' || c == 'c' || c == 'd' || c == 'u' || c == 'p'
		|| c == 'x' || c == 'X' || c == 'i')
		return (1);
	else
		return (0);
}

int	ft_format(va_list list, char c)
{
	int	length;

	length = 0;
	if (c == '%')
		length += ft_putchar('%');
	else if (c == 'c')
		length += ft_putchar(va_arg(list, int));
	else if (c == 's')
		length += ft_putstr_ptr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		length += ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		length += ft_putu(va_arg(list, unsigned int));
	else if (c == 'p')
		length += ft_printptr(va_arg(list, void *));
	else if (c == 'x')
		length += ft_printlhex(va_arg(list, unsigned int));
	else if (c == 'X')
		length += ft_printuhex(va_arg(list, unsigned int));
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		length;

	i = -1;
	length = 0;
	va_start(list, str);
	if (str == 0)
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		if (str[i] == '%' && ft_found(str[i + 1]))
		{
			length += ft_format(list, str[i + 1]);
			i++;
		}
		else if (str[i] || (str[0] == '%' && i == 0))
			(ft_putchar(str[i]), length++);
	}
	va_end(list);
	return (length);
}


int	main(void)
{
	char			*format;
	char			*s;
	char			c;
	int				i;
	int				d;
	unsigned int	u;
	int				x;
	int				X;
	char			*p;

	s = "";
	c = 0;
	i = INT_MIN; //intmin and int_max
	d = 0;
	u = INT_MAX;
	x = 1234567;
	X = 1234567;
	p = 0;
	format = "s:%s, c:%c, p:%p, d:%d, i:%i, u:%u, x:%x, X:%X\n";

	printf("ft_print: \t%d\n", ft_printf(format, s, c, p, d, i, u, x, X));
	printf("printf: \t%d\n", printf(format, s, c, p, d, i, u, x, X));
	printf("\n");
	s = "How";
	c = 85;
	d = 2;
	format = "Hello World %s are %c %dday?\n";
	printf("ft_print: \t%d\n", ft_printf(format, s, c, d));
	printf("printf: \t%d\n", printf(format, s, c, d));
	printf("\n");
	s = "sunnyday ";
	format = "%s%s%s\n";
	printf("ft_print: \t%d\n", ft_printf(format, s, s, s));
	printf("printf: \t%d\n", printf(format, s, s, s));
	printf("\n");
	printf("ft_print: \t%d\n", ft_printf(0));
	printf("printf: \t%d\n", printf(0));
}