/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:12:51 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/06 10:16:43 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned long n)
{
	int	mem;

	mem = 1;
	while (n > 15)
	{
		n = n / 16;
		mem++;
	}
	return (mem);
}

static char	ft_hex_num(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

char	*ft_itoa_hex(unsigned long n)
{
	char				*num;
	int					mem;
	unsigned long		ntemp;

	ntemp = n;
	mem = 0;
	if (ntemp < 0)
	{
		ntemp = -ntemp;
		mem += 1;
	}
	mem = mem + ft_len(ntemp);
	num = malloc (sizeof(char) * (mem + 1));
	if (!num)
		return (NULL);
	num[mem] = '\0';
	while (ntemp > 15)
	{
		num[--mem] = (unsigned char )ft_hex_num((ntemp % 16));
		ntemp = ntemp / 16;
	}
	num[--mem] = ft_hex_num(ntemp);
	if (n < 0)
		num[0] = '-';
	return (num);
}
