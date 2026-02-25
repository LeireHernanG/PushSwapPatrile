/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:51 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/25 12:55:40 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_stack **a)
{
	t_stack	*lastposition;
	t_stack	*new;

	if (!a || !*a)
		return (0);
	lastposition = *a;
	while (lastposition->next)
	{
		new = lastposition;
		lastposition = lastposition->next;
	}
	lastposition->next = *a;
	*a = lastposition;
	new->next = NULL;
	write(1, "rra\n", 3);
	return (1);
}

int	ft_rrb(t_stack **b)
{
	t_stack	*lastposition;
	t_stack	*new;

	if (!b || !*b)
		return (0);
	lastposition = *b;
	while (lastposition->next)
	{
		new = lastposition;
		lastposition = lastposition->next;
	}
	lastposition->next = *b;
	*b = lastposition;
	new->next = NULL;
	write(1, "rrb\n", 3);
	return (1);
}

int	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(&a);
	ft_rrb(&b);
	write(1, "rrr\n", 3);
	return (1);
}