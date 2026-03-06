/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:21:00 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/06 11:47:30 by pmieres-         ###   ########.fr       */
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

void	ft_benchmark(int fd, int algorithm, t_totalmoves *m, float disorder)
{
	ft_printf(fd, "[bench] disorder: %d.%d%%", (int)(disorder * 100), (int)(disorder
			* 100000) % 100);
	if (algorithm == -1 || algorithm == 1)
		ft_printf(fd, "\n[bench] strategy: Simple / O(n^2)");
	else if (algorithm == -2 || algorithm == 2)
		ft_printf(fd, "\n[bench] strategy: Medium / O(n√n)");
	else if (algorithm == -3 || algorithm == 3)
		ft_printf(fd, "\n[bench] strategy: Complex / O(n log n)");
	else if (algorithm == -4 || algorithm == 4)
	{
		ft_printf(fd, "\n[bench] strategy: Adaptive ");
		if (disorder < 0.2)
			ft_printf(fd, "/ O(n^2)");
		else if (0.2 <= disorder && disorder < 0.5)
			ft_printf(fd, "/ O(n√n)");
		else if (disorder >= 0.5)
			ft_printf(fd, "O(n log n)");
	}
	ft_printf(fd, "\n[bench] total_ops: %d", m->sa + m->sb + m->pa + m->pb
		+ m->ra + m->rb + m->rra + m->rrb);
	ft_printf(fd, "\n[bench] sa :  %d  sb :  %d  pa :  %d  pb :  %d", m->sa,
		m->sb, m->pa, m->pb);
	ft_printf(fd, "\n[bench] ra :  %d  rb :  %d   rra : %d   rrb : %d \n", m->ra,
		m->rb, m->rra, m->rrb);
}
