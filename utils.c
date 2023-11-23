/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:27:49 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/22 21:03:33 by ishenriq         ###   ########.org.br   */
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
	if (!str)
		return (ft_putstr("(null)"));
	while(*str != '\0')
	{
		ft_putchar((int) *str);
		++count;
		++str;
	}
	return (count);
}

int	ft_putnmb(long nb, int base, char content)
{
	int	count;
	char	*character;

	count = 0;
	if (content == 'X')
		character = "0123456789ABCDF";
	else
		character = "0123456789abcdf";
	if (nb < 0)
	{
		write(1, "-", 1);
		return ft_putnmb(-nb, base, content) + 1;
	}
	else if (nb < base)
		return	ft_putchar(character[nb]);
	else
	{
		count = ft_putnmb(nb/base, base, content);
		return count + ft_putnmb(nb % base, base, content);
	}
}
