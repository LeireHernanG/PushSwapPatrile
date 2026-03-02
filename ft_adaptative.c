/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:41:44 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/02 11:12:34 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_adaptative(t_stack **a)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		ft_buble_sort(a);
	else if (0.2 <= disorder && disorder < 0.5)
		ft_chunkorder(a);
	else if (disorder >= 0.5)
		ft_radix(a);
	return (0);
}
