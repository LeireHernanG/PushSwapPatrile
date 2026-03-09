/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediumcaca.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:43:45 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/02 19:24:12 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_index(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		max;

	max = ft_lstsize_st(*a) - 1;
	tmp = *a;
	while (tmp)
	{
		tmp->position = 0;
		tmp = tmp->next;
	}
	while (max >= 0)
	{
		tmp = *a;
		while (tmp->position != 0)
			tmp = tmp->next;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content < tmp2->content && tmp2->position == 0)
				tmp = tmp2;
			tmp2 = tmp2->next;
		}
		tmp->position = max--;
	}
}

static void	ft_maxorder(t_stack **a, t_stack **b)
{
	t_stack	*index;
	int		max;

	index = (*b)->next;
	max = 0;
	while (index && (*b)->content > index->content)
	{
		max++;
		index = index->next;
	}
	if (max == ft_lstsize_st(*b) - 1)
		ft_pa(a, b);
	else if ((*b)->next)
		ft_rb(b);
}

int	ft_orderb(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize_st(*b);
	while (*b)
	{
		if ((*b)->next == NULL)
			ft_pa(a, b);
		else
			ft_maxorder(a, b);
	}
	while (size > 0)
	{
		ft_ra(a);
		size--;
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i <= nb)
		i++;
	return (i - 1);
}
/*
int	ft_chunkorder(t_stack **a)
{
	t_stack	*b;
	int		n;
	int		i;
	int		groups;

	b = NULL;
	n = ft_sqrt(ft_lstsize_st(*a));
	groups = ft_lstsize_st(*a) / n;
	if ((ft_lstsize_st(*a) % n) != 0)
		groups++;
	while (groups > 0)
	{
		i = 0;
		if (groups == 1 && (ft_lstsize_st(*a) % n) != 0)
			n = ft_lstsize_st(*a) % n;
		while (i < n)
		{
			ft_pb(a, &b);
			i++;
		}
		ft_orderb(a, &b);
		groups--;
	}
	ft_orderb(&b, a);
	return (0);
} */
