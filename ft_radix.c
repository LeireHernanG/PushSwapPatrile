/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:32:57 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/04 20:30:41 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_index(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmpnext;
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
		tmpnext = tmp->next;
		while (tmpnext)
		{
			if (tmp->content < tmpnext->content && tmpnext->position == 0)
				tmp = tmpnext;
			tmpnext = tmpnext->next;
		}
		tmp->position = max--;
	}
}

static void	ft_sortbit(t_stack **a, t_stack **b, int bit, t_totalmoves **m)
{
	t_stack	*tmp;
	t_stack	*last;
	int		i;
	int		size;
	int		zero;

	zero = 0;
	size = ft_lstsize_st(*a) - 1;
	i = 0;
	while (i++ <= size)
	{
		tmp = *a;
		zero = 0;
		last = (*a)->next;
		while (last && !((last->position >> bit) & 1) && ++zero != 0)
			last = last->next;
		if ((zero == (ft_lstsize_st(*a) - 1) && (tmp->position >> bit) & 1))
			i = size + 2;
		if (((tmp->position >> bit) & 1))
			ft_ra(a, m);
		else
			ft_pb(a, b, m);
	}
	while (*b)
		ft_pa(a, b, m);
}

static int	ft_max_bits(int size)
{
	int	bits;
	int	max;

	if (size < 1)
		return (0);
	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

int	ft_radix(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	int		bit;
	int		bitmax;

	bit = 0;
	b = NULL;
	bitmax = ft_max_bits(ft_lstsize_st(*a) - 1);
	ft_index(a);
	if (ft_lstsize_st(*a) < 10)
	{
		ft_simpleorder(a, totalmoves);
		return (0);
	}
	while (bit <= bitmax)
	{
		ft_sortbit(a, &b, bit, totalmoves);
		bit++;
	}
	return (0);
}
