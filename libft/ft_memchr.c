/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:05:06 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/27 10:20:50 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		if (*temp == (unsigned char) c)
			return (temp);
		temp++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "gfthh";
	int		c = '\0';
	char	*t;

	t = memchr(s, c, 2);
	printf ("%p\n", t);
	t = ft_memchr(s, c, 2);
	printf ("%p", t);
}
*/
