/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:46:27 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/23 12:03:31 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*new ;
	t_list	*lst ;
	t_list	*temp;
	//int		i = 158;

	new = ft_lstnew("adios");
	lst = ft_lstnew("hola");
	ft_lstadd_front(&lst, new);
	temp = lst;
	while (temp != NULL)
	{
		printf("%s", (char *) temp->content);
		temp = temp->next;
	}
}
*/