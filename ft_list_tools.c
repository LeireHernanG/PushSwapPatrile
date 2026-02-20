/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:50:47 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 16:26:51 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_st(t_stack **lst, t_stack *new)
{
	t_stack	*new1;

	new1 = *lst;
	if (lst == NULL && new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new1 = ft_lstlast_st(*lst);
	new1->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_ini_stack(int num, int pos)
{
	t_stack	*node1;

	node1 = (t_stack *)malloc(sizeof(t_stack));
	if (!node1)
		return (0);
	node1->content = num;
	node1->position = pos;
	node1->next = NULL;
	return (node1);
}
t_stack	*ft_lstlast_st(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (lst);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
