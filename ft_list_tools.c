/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:50:47 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/03 12:05:42 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

int	ft_lstsize_st(t_stack *lst)
{
	t_stack	*temp;
	int		size;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

void	ft_lstclear_st(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
