/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:07:33 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/20 17:07:35 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long int	n;
	int			i;

	n = nbr;
	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		i++;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (i + 1);
}
/*

static void	ft_write(char c)
{
	write(1, &c, 1);
}

static long	ft_eval_nbr(long int a)
{
	if (a == 0)
	{
		ft_write('0');
		return (0);
	}
	if (a < 0)
	{
		ft_write('-');
		return (-a);
	}
	return (a);
}

int	ft_putnbr(int nbr)
{
	int			i;
	int			length;
	long int	a;
	char		c[10];

	i = 0;
	length = 0;
	a = nbr;
	a = ft_eval_nbr(a);
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
		ft_write(c[i]);
		i--;
	}
	if (nbr < 0)
		i++;
	return (i);
}
*/
