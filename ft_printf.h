/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:25 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/20 21:53:24 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *content, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
//int	ft_point_hexadecimal(va_list variadic list, int nb);
int	ft_putnmb(long nb, int base);

#endif
