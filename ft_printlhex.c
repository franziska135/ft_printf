/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:26:00 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/22 14:26:04 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlhex(unsigned int n)
{
	int		i;
	char	*hex_l;

	i = 0;
	hex_l = "0123456789abcdef";
	if (n > 15)
	{
		i += ft_printlhex(n / 16);
		i += ft_printlhex(n % 16);
	}
	else
		i += ft_putchar(hex_l[n % 16]);
	return (i);
}
/*int	ft_printlhex(unsigned int n)
{
	int		i;
	char	*hex_l;

	i = 0;
	hex_l = "0123456789abcdef";
	if (n > 15)
	{
		i += ft_printlhex(n / 16);
		i += ft_printlhex(n % 16);
	}
	else
	{
		i += ft_putchar(hex_l[n % 16]);
	}
	return (i);
}*/