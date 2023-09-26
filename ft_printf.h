/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:41:14 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/20 10:41:17 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nbr);
int	ft_putstr_ptr(char *str);
int	ft_putu(unsigned int nbr);
int	ft_printuhex(unsigned int n);
int	ft_printlhex(unsigned int n);
int	ft_printptr(void *ptr);

#endif
