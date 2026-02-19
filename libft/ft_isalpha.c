/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:35:57 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:56 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int		str = 'H';
	char	str2 = '1';
	int	alpha;

	alpha = ft_isalpha(str);
	printf ("%d", alpha);
	alpha = isalpha(str);
	printf ("%d", alpha);
	alpha = ft_isalpha(str2);
	printf ("%d", alpha);
	alpha = isalpha(str2);
	printf ("%d", alpha);
}*/
