/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:08:21 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/23 09:41:42 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
int	main(void)
{
	t_list	*new ;
	t_list	*new2 ;
	int		i = 158;

	new = ft_lstnew(&i);
	printf("%i", *(int *) new->content);

	new2 = ft_lstnew("hola");
	printf("%s", (char *) new2->content);
	printf("%s", (char *) new2->next);
}
*/