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
/*
copy list to check for the right amt of arguments
check int return value
%% prints but how do i incorporate this in checkign for the amt of arg, as % doesnt have one*/
/*return null if null pointer correct?*/
/*check for tabs and \n?*/
#include "ft_printf.h"

/*check if counts correctly*/
/*if too many lines, implement strlen to get rid of length++*/

int	ft_format(va_list list, char str)
{
	int	length;

	length = 0;
	if (str == 'c')
		length += ft_putchar(va_arg(list, int));
	else if (str == 's')
		length += ft_putstr_ptr(va_arg(list, char *));
	else if (str == 'd' || str == 'i')
		length += ft_putnbr(va_arg(list, int));
	else if (str == 'u')
		length += ft_putu(va_arg(list, unsigned int));
	else if (str == 'p')
		length += ft_printptr(va_arg(list, void *));
	else if (str == 'x')
		length += ft_printlhex(va_arg(list, unsigned int));
	else if (str == 'X')
		length += ft_printuhex(va_arg(list, unsigned int));
	else if (str == '%')
		length += ft_putchar('%');
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

	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			length += ft_format(list, str[i + 1]);
			i++;
		}
		else if (str[i])
		{
			ft_putchar(str[i]);
			length++;
		}
	}
	va_end(list);
	return (length);
}

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
	printf("\n");
	A = printf("hello s:%s, c:%c, d:%d, u:%u, prozent:%%, p:%p", b, c, nbr, uns, b);
	printf("\n1:%d\n2:%d", a, A);
	return (0);
}