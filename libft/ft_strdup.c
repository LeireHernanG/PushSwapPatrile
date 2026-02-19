/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:11:41 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/16 19:01:52 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, src, (len + 1));
	return (dup);
}
/*
int	main(void)
{
	char *dup;
	int	i;

	dup = ft_strdup("");
	i = 0;
	printf("%s", dup);
}*/