/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:36:06 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/06 10:14:36 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_un(unsigned int n)
{
	char	c;

	if ((n / 10) < 10 && n > 9)
	{
		c = n / 10 + '0';
		write(1, &c, 1);
	}
	else if (n > 9)
		ft_putnbr_un(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_printf_u(unsigned int n)
{
	int	len;

	len = 1;
	ft_putnbr_un(n);
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
