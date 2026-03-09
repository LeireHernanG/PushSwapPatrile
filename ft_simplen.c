/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:08:51 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/09 14:01:10 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_max(t_stack *a)
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

static int	ft_maxorder(t_stack **a, t_stack **b, t_totalmoves **totalmoves)
{
	int	len;
	int	max;

	len = ft_lstsize_st(*a) - 1;
	max = 0;
	if (is_max(*a))
		ft_pb(a, b, totalmoves);
	else
		ft_ra(a, totalmoves);
	return (0);
}

int	ft_simpleorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	t_stack	*stackb;

	b = NULL;
	while (*a)
		ft_pb(a, &b, totalmoves);
	while (b)
		ft_maxorder(&b, a, totalmoves);
	stackb = *a;
	while (stackb)
	{
		printf("%d\n", stackb->content);
		stackb = stackb->next;
	}
	return (0);
}
