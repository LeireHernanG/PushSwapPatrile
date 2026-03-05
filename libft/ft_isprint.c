/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:14:44 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:54 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char	n = ' ';
	char	n1 = '\n';
	char	n2 = '9';
	int	num;

	num = ft_isprint(n);
	printf ("%d", num);
	printf ("%d", isprint(n));
	num = ft_isprint(n1);
	printf ("%d", num);
	printf ("%d", isprint(n1));
	num = ft_isprint(n2);
	printf ("%d", num);
	printf ("%d", isprint(n2));
}*/
