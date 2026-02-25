/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:43:45 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/25 20:17:14 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
 int	ft_maxorder(t_stack **a, t_stack **b)
{
	t_stack	*index;
	int		max;
	int		size;

	size = ft_lstsize_st(*b);
	if (!a || !b || !*b)
		return (0);
	while (*b)
	{
		index = *b;
		max = 0;
		while (index->content > index->next->content)
			max++;
		if (max == ft_lstsize_st(*b) - 1)
			ft_pa(a, b);
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

 int	ft_chunkorder(t_stack	**a)
{
	t_stack	*b;
	int		n;
	int		i;
	int		groups;
	
	n = ft_sqrt(ft_lstsize_st(*a));
	groups = ft_lstsize_st(a) / n;
	if ((ft_lstsize_st(a) % n) != 0)
		groups++;
	while (groups > 0)
	{
		i = 0;
		if (groups == 1)
			n = ft_lstsize_st(a) % n;
		while (i < n)
		{
			ft_pb(a, &b);
			i++;
		}
		ft_maxorder(a, &b);
		groups--;
	}
}
int main(void)
{
	int	 n;
	n = 24;
	printf("%d", ft_sqrt(n));
	return (1);
}
