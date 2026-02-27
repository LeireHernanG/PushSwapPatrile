/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:32:57 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/27 19:35:36 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sortbit(t_stack **a, t_stack **b, int bit, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i <= size)
	{
		if (!((tmp->position >> bit) & 1))
			ft_pb(a, b);
		else
			ft_ra(a);
		tmp = *a;
		i++;
	}
	while (*b)
		ft_pa(a, b);
}

int	ft_max_bits(int size)
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

int	ft_radix(t_stack **a)
{
	t_stack	*b;
	int		bit;
	int		size;
	int		bitmax;

	bit = 0;
	size = ft_lstsize_st(*a) - 1;
	bitmax = ft_max_bits(size);
	ft_index(a);
	while (bit <= bitmax)
	{
		ft_sortbit(a, &b, bit, size);
		bit++;
	}
	return (0);
}
