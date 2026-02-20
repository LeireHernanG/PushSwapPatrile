/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:49:58 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/22 11:33:30 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	mem;

	mem = 1;
	while (n > 9)
	{
		n = n / 10;
		mem++;
	}
	return (mem);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			mem;
	long		ntemp;

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
	while (ntemp > 9)
	{
		num[--mem] = (ntemp % 10) + '0';
		ntemp = ntemp / 10;
	}
	num[--mem] = ntemp + '0';
	if (n < 0)
		num[0] = '-';
	return (num);
}
/*
int	main(void)
{
	int		i = -40;

	printf("%s", ft_itoa(i));
}
*/
