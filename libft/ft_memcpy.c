/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:25:05 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/23 11:09:59 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "hola que tal";
	char	d[] = "hola que tal";
	char	*src;
	char	*src2;
	size_t	nb;

	nb = 5;
	src = dest + 3;
	src2 = d +3;
	memcpy(d, src2, nb);
	printf("%s\n", d);
	ft_memcpy(dest, src, nb);
	printf("%s", dest);
}*/
/*
int	main(void)
{
	int	dest[] = {1};
	int	d[] = {1};
	int	src[] = {3, 34, 3};
	size_t	nb;

	nb = 5;
	memcpy(d, src, nb);
	printf("%d\n", d[0]);
	ft_memcpy(dest, src, nb);
	printf("%d", dest[0]);
}
*/