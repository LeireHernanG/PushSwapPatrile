/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:10:08 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:50 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	i = 0;
	ss = (unsigned char *)s;
	while (i < n)
	{
		ss[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	*s;
	int		c;
	size_t	n;
	int		s;
	int		c;
	size_t	n;

	s = NULL;
	c = 300;
	n = 20;
	memset(s, c, n);
	printf("%s", s);
	ft_memset(s, c, n);
	printf("%s", s);
	return (0);
}*/
/*
int	main(void)
{
	int	s[] = {4, 54, 7};
	int	c = 2;
	size_t n = 20;
	memset(s, c, n);
	printf("%d\n", s[0]);
	ft_memset(s, c, n);
	printf("%d", s[0]);
	return (0);
}
*/