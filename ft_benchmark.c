/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:21:00 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/04 12:01:36 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_totalmoves	*ft_ini_total_moves(void)
{
	t_totalmoves	*node1;

	node1 = (t_totalmoves *)malloc(sizeof(t_totalmoves));
	if (!node1)
		return (0);
	node1->sa = 0;
	node1->sb = 0;
	node1->pa = 0;
	node1->pb = 0;
	node1->ra = 0;
	node1->rb = 0;
	node1->rra = 0;
	return (node1);
}
void	ft_benchmark(int algorithm, t_totalmoves *totalmoves, float disorder)
{
	float e;
	int r;
	e = disorder * 100;
	r = (int)(disorder * 100000) % 100;
	printf("[bench] disorder: %d.%d%%", (int)e, r);
	if (algorithm == -1)
		printf("\n[bench] strategy: Simple / O(n^2)");
	else if (algorithm == -2)
		printf("\n[bench] strategy: Medium / O(n√n)");
	else if (algorithm == -3)
		printf("\n[bench] strategy: Complex / O(n log n)");
	else if (algorithm == -4)
		printf("\n[bench] strategy: Adaptive");
	printf("\n[bench] total_ops: %d", totalmoves->sa + totalmoves->sb
		+ totalmoves->pa + totalmoves->pb + totalmoves->ra + totalmoves->rb + totalmoves->rra);
	printf("\n[bench] sa :  %d  sb :  %d  pa :  %d  pb :  %d", totalmoves->sa,
		totalmoves->sb, totalmoves->pa, totalmoves->pb);
	printf("\n[bench] ra :  %d  rb :  %d   rra : %d", totalmoves->ra, totalmoves->rb, totalmoves->rra);
}