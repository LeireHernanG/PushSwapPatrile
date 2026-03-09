/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:00:20 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/04 21:02:41 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i <= nb)
		i++;
	return (i - 1);
}

static void	ft_set_zero(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->position = 0;
		tmp = tmp->next;
	}
}

static void	ft_norm(int n, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*comp;
	int		max;
	int		i;

	max = n;
	while (n-- > 1)
	{
		i = 0;
		while (i < max)
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
			i++;
		}
	}
}

void	ft_chunkorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	int		n;
	int		size;
	int		max;

	b = NULL;
	n = ft_sqrt(ft_lstsize_st(*a));
	ft_set_zero(a);
	ft_norm(n, a);
	max = -1;
	while (++max < n)
	{
		size = ft_lstsize_st(*a);
		while (size-- > 0)
		{
			if ((ft_lstlast_st(*a))->position == max && max < n - 1)
				ft_rra(a, totalmoves);
			if (max == (n - 1) || (*a)->position == max)
				ft_pb(a, &b, totalmoves);
			else
				ft_ra(a, totalmoves);
		}
	}
	*a = b;
	ft_simpleorder(a, totalmoves);
}
