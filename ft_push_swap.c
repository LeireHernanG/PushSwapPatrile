/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:40:13 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/09 14:01:29 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rightorder(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next && a->content < a->next->content)
	{
		a = a->next;
	}
	if (a->next == NULL)
		return (1);
	return (0);
}

static int	ft_selection(int algoritm, t_stack **a, t_totalmoves **totalmoves)
{
	if (ft_rightorder(*a))
		return (0);
	if (algoritm == 1 || algoritm == -1)
		ft_simple(a, totalmoves);
	else if (algoritm == 2 || algoritm == -2)
		ft_chunkorder(a, totalmoves);
	else if (algoritm == 3 || algoritm == -3)
		ft_radix(a, totalmoves);
	else
		ft_adaptive(a, totalmoves);
	return (0);
}

int	main(int argc, char **argv)
{
	int				algorithm;
	t_stack			*stacka;
	t_totalmoves	*totalmoves;
	float			disorder;

	stacka = NULL;
	if (argc < 1)
		return (write(2, "Error\n", 6), 1);
	algorithm = control_errors(argc, argv);
	if (algorithm == 0)
		return (write(2, "Error\n", 6), 1);
	if (fill_stack(argc, argv, &stacka) == 1)
	{
		ft_lstclear_st(&stacka);
		return (write(2, "Error\n", 6), 1);
	}
	totalmoves = ft_ini_total_moves();
	disorder = compute_disorder(stacka);
	ft_selection(algorithm, &stacka, &totalmoves);
	if (algorithm < 0)
		ft_benchmark(2, algorithm, totalmoves, disorder);
	ft_lstclear_st(&stacka);
	free(totalmoves);
	return (0);
}
