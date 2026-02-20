/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:12:29 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:41 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c + ('A' - 'a');
	return (c);
}
/*
int	main(void)
{
	char	p1 = 'h';
	char	p2 = 'H';
	char	p3 = ' ';
	char 	n;

	n = toupper(p1);
	printf ("%c", n);
	n = toupper(p2);
	printf ("%c", n);
	n = toupper(p3);
	printf ("%c", n);
}*/
