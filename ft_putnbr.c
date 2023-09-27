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
