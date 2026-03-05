/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:08:51 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/05 15:39:11 by pmieres-         ###   ########.fr       */
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

static int	ft_max_is_last(t_stack **a, int len)
{
	int		max;
	t_stack	*last;
	t_stack	*index;

	max = 0;
	index = *a;
	last = ft_lstlast_st(*a);
	while (index->next)
	{
		if (last->content > index->content)
			max++;
		index = index->next;
	}
	if (max == len)
		return (1);
	else
		return (0);
}

static int	ft_maxorder(t_stack **a, t_stack **b, t_totalmoves **totalmoves)
{
	int	len;
	int	max;

	len = ft_lstsize_st(*a) - 1;
	max = 0;
	if (len != 0 && ft_max_is_last(a, len))
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
		ft_maxorder(a, &b, totalmoves);
	*a = b;
	return (0);
}
