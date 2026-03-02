/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:40:13 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/02 12:24:08 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_selection(int algoritm, t_stack **a)
{
	if (algoritm == 1)
		ft_buble_sort(a);
	else if (algoritm == 2)
		ft_chunkorder(a);
	else if (algoritm == 3)
		ft_radix(a);
	else
		ft_adaptative(a);
	return (0);
}
int	main(int argc, char **argv)
{
	int		algorithm;
	t_stack	*stackA;
	
	if (argc <= 1)
		return (1);
	algorithm = control_errors(argc, argv);
	if (algorithm == 0)
		return (1);
	stackA = fill_stack(argc, argv);
	
	ft_selection(algorithm,&stackA);
	return (0);
}
