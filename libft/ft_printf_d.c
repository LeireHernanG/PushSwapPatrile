/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:09:04 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/06 11:20:34 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_d(int n, int fd)
{
	int		len;
	long	neg;

	len = 1;
	ft_putnbr_fd(n, fd);
	neg = n;
	if (neg < 0)
	{
		len++;
		neg = -neg;
	}
	while (neg > 9)
	{
		neg = neg / 10;
		len++;
	}
	return (len);
}
