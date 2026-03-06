/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:39:04 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/06 11:21:26 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hex(unsigned int n, char x, int fd)
{
	char	*hex;
	int		nchar;
	int		i;

	i = 0;
	hex = ft_itoa_hex(n);
	if (!hex)
		return (-1);
	if (x == 'X')
	{
		while (hex[i])
		{
			hex[i] = ft_toupper(hex[i]);
			i++;
		}
	}
	ft_putstr_fd(hex, fd);
	nchar = ft_strlen(hex);
	free(hex);
	return (nchar);
}
