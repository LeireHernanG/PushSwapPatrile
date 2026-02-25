/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buble_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:17:47 by pmieres-          #+#    #+#             */
/*   Updated: 2026/02/25 13:11:11 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static int	ft_rightorder(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next && a->content < a->next->content)
	{
		a = a->next;
	}
	if (a->next == NULL)
		return (1);
	return (0);
}

static int	round_a(t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	if (ft_rightorder(*a))
		return (count);
	while (*a)
	{
		if ((*a)->next && (*a)->content > (*a)->next->content)
			ft_sa(a);
		ft_pb(a, b);
		if ((*b)->next)
			ft_rb(b);
		count++;
	}
	return (count);
}

static int	round_b(t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	if (ft_rightorder(*b))
		return (count);
	while (*b)
	{
		if ((*b)->next && (*b)->content > (*b)->next->content)
			ft_sb(b);
		ft_pa(a, b);
		if ((*a)->next)
			ft_ra(a);
		count++;
	}
	return (count);
}

int	ft_buble_sort(t_stack **a)
{
	int		order;
	t_stack	*b;

	order = 1;
	b = NULL;
	while (order > 0)
	{
		order = 0;
		if (!*a)
			order = round_b(a, &b);
		else
			order = round_a(a, &b);
	}
	return (1);
}
