/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:27:49 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/20 21:50:16 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c , 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while(*str)
		count += ft_putchar((int) *str++);
	return (count);
}

//int	ft_point_hexadecimal(va_list variadic list, int nb);

int	ft_putnmb(long nb, int base)
{
	int	count;
	char	*character;

	count = 0;
	character = "0123456789abcdf";
	if (nb < 0)
	{
		write(1, "-", 1);
		return (ft_putnmb(-nb, base) + 1);
	}
	else if (nb < base)
		ft_putchar(character[nb]);
	else
	{
		count = ft_putnmb(nb/base, base);
		return (count + ft_putnmb(nb % base, base));
	}
}
