/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:12:48 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/26 18:14:48 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if ((unsigned char)s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "teste";
	int		c = 'e';
	char	*t;

	t = strchr(s, c);
	
	t = ft_strchr(s, 357);
	printf ("%s", t);
	
}
*/