/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:39:56 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/25 13:39:59 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_adr(unsigned long long int n)
{
	int		i;
	char	*hex_l;

	i = 0;
	hex_l = "0123456789abcdef";
	if (n > 15)
	{
		i += ft_print_adr(n / 16);
		i += ft_print_adr(n % 16);
	}
	else
		i += ft_putchar(hex_l[n % 16]);
	return (i);
}

int	ft_printptr(void *ptr)
{
	unsigned long long int	n;
	int						i;

	i = 0;
	n = (unsigned long long int)ptr;
	if (!ptr)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	i += write(1, "0x", 2);
	i += ft_print_adr(n);
	return (i);
}
