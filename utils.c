/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:27:49 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/27 20:19:36 by ishenriq         ###   ########.org.br   */
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


int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_count_digits(size_t n, int base_lenght)
{
	unsigned int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		digits++;
		n /= base_lenght;
	}
	return (digits);
}

char	*ft_ulitohex(unsigned long int n, char *base_str)
{
	unsigned long int	int_to_hex;
	size_t	digits;
	int	base_lenght;
	char	*result;

	base_lenght = ft_strlen(base_str);
	int_to_hex = n;
	digits = ft_count_digits(n, base_lenght);
	result = malloc(digits + 1);
	if (!result)
		return (0);
	result[digits--] = '\0';
	while (int_to_hex > 0)
	{
		result[digits--] = base_str[int_to_hex % base_lenght];
		int_to_hex /= base_lenght;
	}
	if (digits == 0 && result[1] == '\0')
		result[0] = '0';
	return (result);

}

char	*ft_uitohex(unsigned int n, char *base_str)
{
	unsigned int	int_to_hex;
	size_t	digits;
	int	base_lenght;
	char	*result;
	unsigned int	mod;

	base_lenght = ft_strlen(base_str);
	int_to_hex = n;
	digits = ft_count_digits(n, base_lenght);
	result = malloc(digits + 1);
	if (!result)
		return (0);
	result[digits--] = '\0';
	while (int_to_hex > 0)
	{
		mod = int_to_hex % base_lenght;
		result[digits--] = base_str[mod];
		int_to_hex /= base_lenght;
	}
	if (digits == 0 && result[1] == '\0')
		result[0] = '0';
	return (result);

}

int	ft_point_voidhex(unsigned long int str)
{
	int	count;
	char	*pointer;

	count = 0;
	if (!str)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	pointer = ft_ulitohex(str, "0123456789abcdef");
	count += ft_putstr(pointer);
	free(pointer);
	return (count);
}

unsigned int	ft_putnmb_hex(unsigned int nb, char content)
{
	char	*int_to_hex;
	unsigned int	count;

	count = 0;
	int_to_hex = NULL;
	if (content == 'x')
		int_to_hex = ft_uitohex(nb, "0123456789abcdef");
	else if (content == 'X')
		int_to_hex = ft_uitohex(nb, "0123456789ABCDEF");
	count = ft_putstr(int_to_hex);
	free(int_to_hex);
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
