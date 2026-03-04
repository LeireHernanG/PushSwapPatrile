/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:32:57 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/04 18:34:02 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_index(t_stack **a)
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

static void	ft_sortbit(t_stack **a, t_stack **b, int bit,
		t_totalmoves **totalmoves)
{
	t_stack	*tmp;
	int		i;
	int		size;
	t_stack	*last;
	//t_stack	*h;
	int		one;

	one = 0;
	size = ft_lstsize_st(*a) - 1;
	tmp = *a;
	i = 0;
	while (i++ <= size)
	{
		one = 0;
		last = (*a)->next;
		while (last && !((last->position >> bit) & 1))
		{
			one++;
			last = last->next;
		}
		if ((one == (ft_lstsize_st(*a) - 1) && (tmp->position >> bit) & 1))
		{
			ft_ra(a, totalmoves);
			i = size + 2;
		}
		else if (!((tmp->position >> bit) & 1))
			ft_pb(a, b, totalmoves);
		else
			ft_ra(a, totalmoves);
		tmp = *a;
	}
	while (*b)
		ft_pa(a, b, totalmoves);
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
	if ( ft_lstsize_st(*a) < 10)
	{
		ft_simpleorder(a , totalmoves);
		return(0);
	}
	while (bit <= bitmax)
	{
		ft_sortbit(a, &b, bit, totalmoves);
		bit++;
	}
	return (0);
}
