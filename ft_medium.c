/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:00:20 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/04 16:49:31 by pmieres-         ###   ########.fr       */
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

static void	ft_norm(int n, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*comp;
	int		max;
	int		i;

	max = n;
	while (n > 1)
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
			tmp->position = n - 1;
			i++;
		}
		n--;
	}
}

int	ft_chunkorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	int		n;
	int		i;
	int		size;
	t_stack	*last;
	t_stack	*tmp;
	t_stack	*h;
	int		max;

	b = NULL;
	n = ft_sqrt(ft_lstsize_st(*a));
	tmp = *a;
	while (tmp)
	{
		tmp->position = 0;
		tmp = tmp->next;
	}
	ft_norm(n, a);
	h = *a;
	while (h)
	{
		printf("%d\n", h->position);
		h = h->next;
	}
	max = 0;
	while (max < n)
	{
		i = 0;
		size = ft_lstsize_st(*a);
		while (i++ < size)
		{
			last = ft_lstlast_st(*a);
			if (last->position == max && max < n - 1)
			{
				ft_rra(a, totalmoves);
				ft_pb(a, &b, totalmoves);
			}
			else if (max == (n - 1))
				ft_pb(a, &b, totalmoves);
			else
			{
				if ((*a)->position == max)
					ft_pb(a, &b, totalmoves);
				else
					ft_ra(a, totalmoves);
			}
		}
		max++;
	}
	*a = b;
	h = *a;
	while (h)
	{
		printf("%d\n", h->content);
		h = h->next;
	}
	ft_simpleorder(a, totalmoves);
	h = *a;
	while (h)
	{
		printf("%d\n", h->content);
		h = h->next;
	}
	return (0);
}
/* static void	ft_normchunk(int n, t_stack **inichunk)
{
	t_stack	*tmp;
	int		max;
	t_stack	*tmp2;
	int		i;
	int		j;

	max = n;
	while (max > 0)
	{
		i = n;
		j = n;
		tmp = *inichunk;
		while (tmp->position != 0 && i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		tmp2 = tmp->next;
		while (j > 0)
		{
			while (i > 1)
			{
				if (tmp2 && tmp->content > tmp2->content && tmp2->position == 0)
					tmp = tmp2;
				tmp2 = tmp2->next;
				i--;
			}
			tmp->position = max;
			j--;
		}
		max--;
	}
}

static void	ft_indexmed(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*inichunk;
	int		groups;

	//int		i;
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
 */

/*int	ft_chunkorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	int		n;
	int		i;
	int		size;
	t_stack	*last;
	t_stack	*h;

	// int		j;
	b = NULL;
	n = ft_sqrt(ft_lstsize_st(*a));
	ft_indexmed(a, n);
	h = *a;
	while (h)
	{
		printf("%d\n", h->position);
		h = h->next;
	}
	while (n > 0)
	{
		i = 0;
		size = ft_lstsize_st(*a);
		while (i++ < size)
		{
			last = ft_lstlast_st(*a);
			if (last->position == n && n > 1)
			{
				ft_rra(a, totalmoves);
				ft_pb(a, &b, totalmoves);
			}
			else
			{
				if ((*a)->position == n)
					ft_pb(a, &b, totalmoves);
				else
				{
					j = 0;
					last = *a;
					while (last && last->position != n)
					{
						j++;
						last = last->next;
					}
					if (j + i < size)
						ft_ra(a, totalmoves);
				else
					ft_ra(a, totalmoves);
			}
		}
		n--;
	}
	*a = b;
	h = *a;
	i = 0;
	while (h)
	{
		printf("%d\n", h->content);
		h = h->next;
	}
	ft_simpleorder(a, totalmoves);
	return (0);
}*/
