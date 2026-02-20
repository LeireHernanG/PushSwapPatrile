/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:07:33 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/22 16:08:08 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && i < ft_strlen(big))
	{
		j = 0;
		if (big[i] == little[j])
		{
			j++;
			while (little[j] && little[j] == big[(i + j)] && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*s1= "MZIRIBMZIRIBMZE123";
	char	*s2 =  "MZIRIBMZE";
	size_t max = strlen(s2);
	
	//printf ("%s\n", strnstr(s1, s2, max));
	printf ("%s", ft_strnstr(s1, s2, max));
}*/