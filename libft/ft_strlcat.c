/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:54 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:48 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	int		i;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size <= len_d)
		return (size + len_s);
	while (src[i] && (len_d + i) < (size -1))
	{
		dst[(len_d + i)] = src[i];
		i++;
	}
	dst[(len_d + i)] = '\0';
	return (len_d + len_s);
}
/*
int	main(void)
{
	char	src[] = "hola";
	char	dest[] = "hello";

	//ft_strlcat(dest, src, 3);
	printf ("%zu", ft_strlcat(dest, src, 14));
	printf ("%s", dest);
}
*/