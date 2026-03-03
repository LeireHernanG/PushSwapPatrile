/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:40:13 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/03 18:31:05 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_selection(int algoritm, t_stack **a, t_totalmoves **totalmoves)
{
	if (algoritm == 1 || algoritm == -1)
		ft_buble_sort(a, totalmoves);
	else if (algoritm == 2 || algoritm == -2)
		ft_chunkorder(a, totalmoves);
	else if (algoritm == 3 || algoritm == -3)
		ft_radix(a, totalmoves);
	else
		ft_adaptative(a, totalmoves);
	return (0);
}

int	main(int argc, char **argv)
{
	int				algorithm;
	t_stack			*stacka;
	t_totalmoves	*totalmoves;
	float			disorder;

	stacka = NULL;
	totalmoves = ft_ini_total_moves();
	if (argc < 1)
		return (write(2, "Error\n", 6), 1);
	algorithm = control_errors(argc, argv);
	if (algorithm == 0)
		return (1);
	if (fill_stack(argc, argv, &stacka) == 1)
		return (write(2, "Error\n", 6), 1);
	disorder = compute_disorder(stacka);
	ft_selection(algorithm, &stacka, &totalmoves);
	if (algorithm < 0)
		ft_benchmark(algorithm, totalmoves, disorder);
	return (0);
}
