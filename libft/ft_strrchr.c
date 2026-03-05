/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:38:07 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/26 18:16:32 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = 0;
	last = NULL;
	while (i < ft_strlen(s) + 1)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			last = (char *) &s[i];
		i++;
	}
	return (last);
}
/*
int	main(void)
{
	char	s[] = "12a3\0a6";
	int		c = 'a';
	char	*t;

	t = strrchr(s, c);
	printf ("%c", t[1]);
	
}*/
