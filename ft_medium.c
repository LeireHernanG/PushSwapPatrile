/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:00:20 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/02 19:19:33 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normchunk(int n, t_stack **inichunk)
{
	t_stack	*tmp;
	int		max;
	t_stack	*tmp2;
	int		i;

	max = n;
	while (max > 0)
	{
		i = n;
		tmp = *inichunk;
		while (tmp->position != 0 && i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		tmp2 = tmp->next;
		while (i > 1)
		{
			if (tmp2 && tmp->content < tmp2->content && tmp2->position == 0)
				tmp = tmp2;
			tmp2 = tmp2->next;
			i--;
		}
		tmp->position = max--;
	}
}

void	ft_indexmed(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*inichunk;
	int		i;
	int		groups;

	tmp = *a;
	inichunk = *a;
	groups = ft_lstsize_st(*a) / n;
	if ((ft_lstsize_st(*a) % n) != 0)
		groups++;
	while (tmp)
	{
		tmp->position = 0;
		tmp = tmp->next;
	}
	while (groups > 0)
	{
		if (groups == 1 && (ft_lstsize_st(*a) % n) != 0)
			n = ft_lstsize_st(*a) % n;
		ft_normchunk(n, &inichunk);
		i = n;
		while (i-- > 0)
			inichunk = inichunk->next;
		groups--;
	}
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
	int		size;

	b = NULL;
	n = ft_sqrt(ft_lstsize_st(*a));
	ft_indexmed(a, n);
	while (n > 0)
	{
		i = 0;
		size = ft_lstsize_st(*a);
		while (i++ < size)
		{
			if ((*a)->position == n)
				ft_pb(a, &b);
			else
				ft_ra(a);
		}
		n--;
	}
	*a = b;
	ft_buble_sort(a);
	return (0);
}
