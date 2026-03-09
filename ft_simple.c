/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_si.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:50:03 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/09 12:56:46 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_simple(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*stackb;
	int		i;
	int		len;
	int		sa;

	len = ft_lstsize_st(*a);
	i = 0;
	sa = 1;
	while (sa)
	{
		sa = 0;
		i = 0;
		while (i < (len - 1))
		{
			if ((*a)->content > (*a)->next->content)
			{
				ft_sa(a, totalmoves);
				sa = 1;
			}
			ft_ra(a, totalmoves);
			i++;
		}
		ft_ra(a, totalmoves);
	}
	stackb = *a;
	while (stackb)
	{
		printf("%d ", stackb->content);
		stackb = stackb->next;
	}
	return (0);
}
