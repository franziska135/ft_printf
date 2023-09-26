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
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			length += ft_format(list, str[i + 1]);
			if (ft_found(str[i + 1]))
				i++;
		}
		else if (str[i])
			(ft_putchar(str[i]), length++);
	}
	va_end(list);
	return (length);
}

int	main(void)
{
	char	*format;

	// format = "%u %s %x";
	// printf("\n%d\n", ft_printf(format, INT_MAX + 100, "abcdef", 12345));
	// printf("\n%d\n", printf(format, INT_MAX + 100, "abcdef", 12345));
	// printf("\n");
	// format = "'%c'";
	// printf("\n%d\n", ft_printf(format, ""));
	// printf("\n%d\n", printf(format, ""));
	// printf("\n");
	// format = "%p";
	// printf("\n%d\n", ft_printf(format, 0));
	// printf("\n%d\n", printf(format, 0));
	// printf("\n");
	// format = "hello %% test %i %d %% %%%d%";
	// printf("\n%d\n", ft_printf(format, -13, 0, INT_MIN));
	// printf("\n%d\n", printf(format, -13, 0, INT_MIN));
	// printf("\n");
	printf("\n%d\n", ft_printf("%w"));
	printf("\n%d\n", printf("%w"));
}
/* //2. Main von davor
int	main(void)
{
	char			*b;
	char			c;
	int				nbr;
	unsigned int	uns;
	int				a;
	int				A;

	b = "you";
	c = 82;
	nbr = -1235;
	uns = 1234;
	a = ft_printf("hello s:%s, c:%c, d:%d, u:%u, prozent:%%, p:%p", b, c, nbr, uns, b);
	a = ft_printf(" NULL %s NULL ", NULL);
	printf("\n");
	A = printf("hello s:%s, c:%c, d:%d, u:%u, prozent:%%, p:%p", b, c, nbr, uns, b);
	A = printf(" NULL %s NULL ", NULL);
	printf("\n1:%d\n2:%d", a, A);
	return (0);
}*/
