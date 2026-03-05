/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:16:42 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:47 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size > len)
	{
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	else if (size > 0)
	{
		ft_memcpy(dst, src, (size - 1));
		dst[(size - 1)] = '\0';
	}
	return (len);
}
/*
int	main(void)
{
	size_t	size;
	size_t	size2;
	char	dest[] = "ad";
	char	src[] = "hola";

	size = 5;
	printf ("%zu", size);
	printf ("%zu", ft_strlcpy(dest, src, size));
	printf ("%s", dest);
	printf ("%zu", ft_strlen(dest));
}
*/