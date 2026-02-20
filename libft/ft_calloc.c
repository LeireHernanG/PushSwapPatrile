/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:00:53 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/22 13:51:57 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size && size != 0)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
/*
int	main(void)
{
	int	*ca;
	int		i; 
	i = 0;
	ca = ft_calloc(536870912, sizeof(int));
	while (i < 50) 
	{
		if (ca[i] != 0) 
		{
			printf("Error: El elemento %c no está .\n", ca[i]);
			//return (1);
		}
		i++;
	}
	free(ca);
}*/
