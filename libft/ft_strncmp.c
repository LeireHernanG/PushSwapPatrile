/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:30:45 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/22 14:23:22 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((s1[i] || s2[i]) && n == i)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	*s1 = "test";
	char	*s2 = "testss";
	int		equal;

	equal = ft_strncmp(s1, s2, 7);
	printf ("%d\n", equal);
	equal = strncmp(s1, s2, 7);
	printf ("%d\n", equal);
	equal = ft_strncmp(s1, s2, 3);
	printf ("%d", equal);
}
*/