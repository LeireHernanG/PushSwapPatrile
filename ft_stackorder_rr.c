/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:51 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/09 13:05:13 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_stack **a, t_totalmoves **totalmoves)
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
	(*totalmoves)->rra++;
	write(1, "rra\n", 4);
	return (1);
}

int	ft_rrb(t_stack **b, t_totalmoves **totalmoves)
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
	(*totalmoves)->rrb++;
	write(1, "rrb\n", 4);
	return (1);
}
