/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:08:51 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/04 16:32:32 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	is_max(t_stack *a)
{
	t_stack	*index;
	int		max;

	max = 0;
	index = (a)->next;
	while (index && (a)->content > index->content)
	{
		max++;
		index = index->next;
	}
	if (max == ft_lstsize_st(a) - 1)
		return (1);
	else
		return (0);
}

static int	ft_minorder(t_stack **a, t_stack **b, t_totalmoves **totalmoves)
{
	t_stack	*index;
	t_stack	*last;
	int		len;
	int		max;

	len = ft_lstsize_st(*a) - 1;
	index = *a;
	last = ft_lstlast_st(*a);
	max = 0;
	while (index->next)
	{
		if (last->content > index->content)
			max++;
		index = index->next;
	}
	if (len != 0 && max == len)
	{
		ft_rra(a, totalmoves);
		ft_pb(a, b, totalmoves);
		return (0);
	}
	if (is_max(*a))
		ft_pb(a, b, totalmoves);
	else if (is_max((*a)->next))
	{
		ft_sa(a, totalmoves);
		ft_pb(a, b, totalmoves);
	}
	else
		ft_ra(a, totalmoves);
	return (0);
}

int	ft_simpleorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;

	b = NULL;
	while (*a)
		ft_minorder(a, &b, totalmoves);
	*a = b;
	return (0);
}
