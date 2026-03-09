/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fivenum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:07 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/09 12:44:02 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fivenum(t_stack **a, t_totalmoves **totalmoves)
{
	int	size;

	size = ft_lstsize_st(*a);
	if (size == 2)
		ft_sa(a, totalmoves);
	else if (size == 3)
	{
		if ((*a)->content > (*a)->next->content
			&& (*a)->content > (*a)->next->next->content)
			ft_ra(a, totalmoves);
		else if ((*a)->content > (*a)->next->content)
			ft_sa(a, totalmoves);
		else
			ft_rra(a, totalmoves);
		if ((*a)->content > (*a)->next->content)
			ft_sa(a, totalmoves);
	}
	else
		ft_simple(a, totalmoves);
	return (0);
}
