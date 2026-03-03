/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:41:44 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/03 16:47:47 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_adaptative(t_stack **a,t_totalmoves **totalmoves)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		ft_buble_sort(a,totalmoves);
	else if (0.2 <= disorder && disorder < 0.5)
		ft_chunkorder(a,totalmoves);
	else if (disorder >= 0.5)
		ft_radix(a,totalmoves);
	return (0);
}
