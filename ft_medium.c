/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:43:45 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/27 19:34:53 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	else
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

int	ft_chunkorder(t_stack **a)
{
	t_stack	*b;
	int		n;
	int		i;
	int		groups;

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
}
