/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:05:51 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:55 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	int	p1 = 0;
	int p2 = 128;
	int p3 = -96;

	printf ("%d", ft_isascii(p1));
	printf ("%d", isascii(p1));
	printf ("%d", ft_isascii(p2));
	printf ("%d", isascii(p2));
	printf ("%d", ft_isascii(p3));
	printf ("%d", isascii(p3));
}*/
