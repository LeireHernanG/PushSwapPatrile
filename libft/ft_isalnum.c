/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:53:29 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:58 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	char	p1 = 'Z';
	char	p2 =  '4';
	char	p3 = ' ';

	printf ("v%d", isalnum(p1));
	printf ("f%d", ft_isalnum(p1));
	printf ("v%d", isalnum(p2));
    printf ("f%d", ft_isalnum(p2));
	printf ("v%d", isalnum(p3));
    printf ("f%d", ft_isalnum(p3));
}*/
