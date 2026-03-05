/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:00:03 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/22 12:06:22 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
/*
void	del(void *nod)
{
	free(nod);
	nod = NULL;
}

int	main(void)
{
	t_list	*lst;
	t_list	*temp;

	lst = malloc(sizeof(t_list));
	lst->content = ft_strdup("cero");
	lst->next = malloc(sizeof(t_list));
	lst->next->content = ft_strdup("uno");
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->content = ft_strdup("dos");
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->content = ft_strdup("tres");
	lst->next->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->next->content = ft_strdup("cuatro");
	lst->next->next->next->next->next = NULL;

	ft_lstclear(&(lst->next->next), del);
	temp = lst;
	while (temp != NULL)
	{
		printf("%s\n", (char *) temp->content);
		temp = temp->next;
	}
}
*/