/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:01:34 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/06 10:14:51 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(va_list arg, char c)
{
	int	num;

	num = 0;
	if (c == 'c')
		return (ft_printf_char(va_arg(arg, int)));
	else if (c == 's')
		return (ft_printf_str(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_printf_point(va_arg(arg, void *)));
	else if (c == 'd')
		return (ft_printf_d(va_arg(arg, int)));
	else if (c == 'i')
		return (ft_printf_d(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(arg, unsigned int), c));
	else if (c == '%')
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	ft_putchar_fd('%', 1);
	ft_putchar_fd(c, 1);
	return (2);
}

static int	write_sum(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	char	*param;
	int		i;
	int		num;

	i = 0;
	num = 0;
	if (!str)
		return (-1);
	va_start(arg, str);
	param = ft_strchr(str, '%');
	while (&str[i] <= param || str[i])
	{
		if (&str[i] == param && str[i + 1] != '\0')
		{
			num += ft_type(arg, str[++i]);
			param = ft_strchr(&str[++i], '%');
		}
		else if (&str[i] == param && str[i + 1] == '\0')
			return (-1);
		else
			num += write_sum(str[i++]);
	}
	va_end(arg);
	return (num);
}
