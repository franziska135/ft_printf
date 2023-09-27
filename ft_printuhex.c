/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:26:42 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/25 13:26:44 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuhex(unsigned int n)
{
	int			i;
	char		*hex_u;

	i = 0;
	hex_u = "0123456789ABCDEF";
	if (n > 15)
	{
		i += ft_printuhex(n / 16);
		i += ft_printuhex(n % 16);
	}
	else
		i += ft_putchar(hex_u[n % 16]);
	return (i);
}
