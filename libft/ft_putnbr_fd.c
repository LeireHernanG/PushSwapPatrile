/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:50:30 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/23 09:32:03 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nt;

	nt = n;
	if (n < 0)
	{
		write (fd, "-", 1);
		nt = nt * -1;
	}
	if ((nt / 10) < 10 && nt > 9)
	{
		c = nt / 10 + '0';
		write (fd, &c, 1);
	}
	else if (nt > 9)
		ft_putnbr_fd (nt / 10, fd);
	c = (nt % 10) + '0';
	write (fd, &c, 1);
}
/*
int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
}*/