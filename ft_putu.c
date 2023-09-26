/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:33:37 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/22 11:33:39 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int nbr)
{
	unsigned long int	n;
	int					i;

	n = nbr;
	i = 0;

	if (n > 9)
		i += ft_putu(n / 10);
	ft_putchar(n % 10 + '0');
	return (i + 1);

}
/*
int	ft_putu(unsigned int n)
{
	unsigned long int	nbr;
	int	i;

	nbr = n;
	i = 0;
	if (nbr > 9)
	{
		i += ft_putu(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
	return (i);
}
*/
/*
int	ft_putu(unsigned int nbr)
{
	int					i;
	int					length;
	long unsigned int	a;
	char				c[10];

	i = 0;
	length = 0;
	a = nbr;
	while (a > 0)
	{
		c[i] = a % 10 + '0';
		a /= 10;
		i++;
		length++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
	}
	return (i);
}
*/