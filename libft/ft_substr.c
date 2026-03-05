/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:29:32 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/27 11:59:01 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	sub = malloc (sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int main(void)
{
	char 	*s;
	char	*r;

	s = NULL;
	r = ft_substr(s, 1, 1);
	printf("%s", r);
}*/