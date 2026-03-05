/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:36:16 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/27 12:18:08 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		nd;
	char	*trim;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	st = 0;
	nd = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[st]) != NULL && s1[st])
		st++;
	while (ft_strchr(set, s1[nd]) != NULL && nd > 0)
		nd--;
	if (nd >= st)
		trim = malloc (sizeof(char) * (nd - st + 2));
	else
		trim = malloc (sizeof(char));
	if (!trim)
		return (NULL);
	while (st <= nd)
		trim[i++] = s1[st++];
	trim[i] = '\0';
	return (trim);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = " . abcd";
	char	*set = " ";

	set =NULL;
	printf("%s", ft_strtrim(s1, set));
}*/