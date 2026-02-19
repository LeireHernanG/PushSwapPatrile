/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:34:29 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/26 18:25:55 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	if (n == i)
		i--;
	return (t1[i] - t2[i]);
}
/*
int	main(void)
{
	char	s1[] = "123456789";
	char	s2[] = "123456789";
	int		equal;

	equal = ft_memcmp(s2, s1, 10);
	printf ("%d", equal);
	// equal = ft_memcmp(s2, s1, -2*sizeof(int));
	// printf ("%d", equal);
	// equal = ft_memcmp(s1, s2, 3*sizeof(int));
	// printf ("%d", equal);
}*/