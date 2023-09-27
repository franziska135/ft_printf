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
