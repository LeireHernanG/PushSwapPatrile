/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mediumcaca.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:43:45 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/06 17:57:31 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* static int	is_max(t_stack *a)
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
	t_stack	*temp;
	t_stack	*max;
	int		rrb;

	b = NULL;
	while (*a)
		ft_maxorder(a, &b, totalmoves);
	while (b)
		ft_pa(a, &b, totalmoves);
	return (0);
}  */
/* static void	max_to_b(t_stack **a, t_stack **b, t_totalmoves **moves)
{
	temp = (*b)->next;
	max = *b;
	rrb = 0;
	while (temp)
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

int	ft_simpleorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	t_stack	*stackb;
	t_stack	*temp;
	t_stack	*temp2;
	int		ord;
	int		mov;

	b = NULL;
	while (*a)
		ft_pb(a, &b, totalmoves);
	while (b)
		max_to_b(a, &b, totalmoves);
	stackb = *a;
	while (stackb)
	{
		printf("%d\n", stackb->content);
		stackb = stackb->next;
	}
	return (0);
} */
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
