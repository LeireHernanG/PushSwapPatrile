/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:49:35 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/27 12:40:41 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapi;

	if (!s || !f)
		return (NULL);
	i = 0;
	mapi = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mapi)
		return (NULL);
	while (s[i])
	{
		mapi[i] = f (i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
/*
char	f(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
}

int main(void)
{
	char	s[] = "hola";
	char	*c;

	c = ft_strmapi(s,f);
	printf("%s", c);
	printf("%lu",sizeof(s));
}*/