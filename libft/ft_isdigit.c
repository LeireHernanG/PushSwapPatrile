/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:24:56 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:54 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char	n1 = '1';
	char	n2 = 'a';
	int		n3 = 256;
	int	num;

	num = ft_isdigit(n1);
	printf("%d", num);
	printf("%d", isdigit(n1));
	num = ft_isdigit(n2);
	printf("%d", num);
	printf("%d", isdigit(n2));
	num = ft_isdigit(n3);
	printf("%d", num);
	printf("%d", isdigit(n3));
}*/
