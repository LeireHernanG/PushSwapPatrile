/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:46:10 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/26 18:58:16 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d > s)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n > 0)
		{
			*d = *s;
			d--;
			s--;
			n--;
		}
	}
	else
		ft_memcpy (dest, src, n);
	return (dest);
}

/*
// primero src lluego destino
int	main(void)
{
	char	src[] = "casas";
	char	src2[] = "casas";
	char	dest[] = "pepe";
	char	d[] = "pepe";
	size_t	nb;

	nb = 5;
	//dest = src + 3;
	//d = src2 + 3;
	ft_memmove(d, src2, nb);
	printf("%s\n", d);
	memmove(dest, src, nb);
	printf("%s", dest);
}*/

/*
// primero dest lluego src
int	main(void)
{
	char	dest[] = "hola que tal";
	char	d[] = "hola que tal";
	char	*src;
	char	*src2;
	size_t	nb;

	nb = 5;
	src = dest + 3;
	src2 = d + 3;
	memmove(d, src2, nb);
	printf("%s\n", d);
	ft_memmove(dest, src, nb);
	printf("%s", dest);
}
*/