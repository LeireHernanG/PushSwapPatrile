/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:43:25 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:43 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - ('A' - 'a');
	return (c);
}
/*
int	main(void)
{
	char	p1 = 'h';
	char	p2 = 'H';
	char	p3 = 0;
	char 	n;

	n = ft_tolower(p1);
	printf ("%c", n);
	n = ft_tolower(p2);
	printf ("%c", n);
	n = tolower(p3);
	printf ("%c", n);
}*/
