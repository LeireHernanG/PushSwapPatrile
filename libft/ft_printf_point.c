/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:32:49 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/06 11:23:00 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_point(void *p, int fd)
{
	char		*hex;
	uintptr_t	dec;
	int			nchar;

	if (p == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	dec = (uintptr_t)p;
	hex = ft_itoa_hex(dec);
	if (!hex)
		return (-1);
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(hex, fd);
	nchar = 2 + ft_strlen(hex);
	free(hex);
	return (nchar);
}
