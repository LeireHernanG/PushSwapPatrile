/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:41:44 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/09 13:01:01 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_adaptive(t_stack **a, t_totalmoves **totalmoves)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (ft_lstsize_st(*a) < 5)
	{
		ft_fivenum(a, totalmoves);
		return (0);
	}
	if (disorder < 0.2)
		ft_simpleorder(a, totalmoves);
	else if (0.2 <= disorder && disorder < 0.5)
		ft_chunkorder(a, totalmoves);
	else if (disorder >= 0.5)
		ft_radix(a, totalmoves);
	return (0);
}
