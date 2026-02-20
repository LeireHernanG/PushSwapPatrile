/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:34:02 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/27 12:38:58 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_memwords(char *s, char c)
{
	int		i;
	int		num;
	char	**split;

	i = 0;
	num = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		num ++;
		while (s[i] == c && s[i])
			i++;
	}
	split = malloc(sizeof(char *) * (num + 1));
	if (!split)
		return (NULL);
	return (split);
}

static int	ft_memsize(char **split, int num, int n)
{
	split[num] = malloc(sizeof(char) * n);
	if (!split[num])
	{
		while (num >= 0)
		{
			free(split[num]);
			num--;
		}
		free(split);
		return (0);
	}
	else
		return (1);
}

static int	ft_find(int n, int choose, char *s, char c)
{
	int	i;

	i = 0;
	if (choose > 0)
	{
		while (s[n] == c && s[n])
			n++;
		return (n);
	}
	else
	{
		while (s[n + i] != c && s[n + i])
			i ++;
		return (i);
	}
}

char	**ft_split(char const *s, char c)
{
	int		num;
	char	**split;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	num = 0;
	j = 0;
	split = ft_memwords((char *)s, c);
	if (!split)
		return (NULL);
	while (s[j])
	{
		j = ft_find(j, 1, (char *)s, c);
		i = ft_find(j, -1, (char *)s, c);
		if (i > 0 && ft_memsize (split, num, i + 1) == 0)
			return (NULL);
		if (i > 0)
			ft_strlcpy (split[num++], &s[j], i + 1);
		j = j + i;
	}
	split[num] = NULL;
	return (split);
}
/*
int	main(void)
{
	char	s[] = "hello!zzzzzzzz";
	char	**split;
	char	c;
	int		i;

	i = 0;
	c = 'z';
	split = ft_split(s, NULL);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}*/