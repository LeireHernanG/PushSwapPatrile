/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:08:52 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/05 15:29:49 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_norm(int n, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*comp;
	int		max;
	int		i;

	max = n;
	ft_set_zero(a);
	while (n-- > 1)
	{
		i = -1;
		while (++i < max)
		{
			tmp = *a;
			while (tmp->position != 0)
				tmp = tmp->next;
			comp = tmp->next;
			while (comp)
			{
				if (tmp->content < comp->content && comp->position == 0)
					tmp = comp;
				comp = comp->next;
			}
			tmp->position = n;
		}
	}
}

static void	max_to_b(t_stack **a, t_stack **b, t_totalmoves **moves)
{
	t_stack	*temp;
	t_stack	*max;
	int		rrb;

	temp = (*b)->next;
	max = *b;
	rrb = 0;
	while (temp && temp->position == (*b)->position)
	{
		if (temp && max->content < temp->content)
			max = temp;
		temp = temp->next;
	}
	while (max != *b)
	{
		rrb++;
		ft_rb(b, moves);
	}
	ft_pa(a, b, moves);
	while (rrb > 0 && (*b)->next)
	{
		ft_rrb(b, moves);
		rrb--;
	}
}

static void	order_last(t_stack **a, t_stack **b, int n, t_totalmoves **moves)
{
	int	i;
	int	t;
	int	max;

	while (*b)
	{
		i = -1;
		while (++i < n)
		{
			max = -1;
			t = n;
			if (i == (n - 1))
				t = (ft_lstsize_st(*b));
			while (++max < t)
			{
				max_to_b(a, b, moves);
			}
		}
	}
}

static void	ft_is_top(int max, t_stack **a, t_stack **b, t_totalmoves **moves)
{
	t_stack	*temp;
	int		place;
	int		size;

	temp = *a;
	place = 0;
	size = ft_lstsize_st(*a);
	while (temp && temp->position != max)
	{
		place++;
		temp = temp->next;
	}
	if (place > size / 2 && place > 1)
	{
		while ((ft_lstlast_st(*a))->position != max)
			ft_rra(a, moves);
		ft_rra(a, moves);
		ft_pb(a, b, moves);
	}
	else
	{
		while ((*a)->position != max)
			ft_ra(a, moves);
		ft_pb(a, b, moves);
	}
}

void	ft_chunkorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	int		n;
	int		len;
	int		size;
	int		max;

	b = NULL;
	len = ft_lstsize_st(*a);
	n = ft_sqrt(len);
	ft_norm(n, a);
	max = -1;
	while (++max < (n - 1))
	{
		size = n;
		if (max == 0)
			size = ((len / n) - n + 1) * n + (len % n);
		while (size-- > 0)
			ft_is_top(max, a, &b, totalmoves);
	}
	while (*a)
		ft_pb(a, &b, totalmoves);
	order_last(a, &b, n, totalmoves);
}
