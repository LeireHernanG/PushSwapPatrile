/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:42:33 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 16:49:51 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stacka)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	t_stack	*nod;
	t_stack	*list;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	list = stacka;
	while (list)
	{
		nod = list->next;
		while (nod)
		{
			total_pairs += 1;
			if (list->content > nod->content)
				mistakes += 1;
			nod = nod->next;
		}
		list = list->next;
	}
	return (mistakes / total_pairs);
}

#include <stdio.h>

int	main(void)
{
	t_stack	*list;

	write(1, "5", 1);
	ft_lstadd_back_st(&list, ft_ini_stack(4, 0));
	write(1, "4", 1);
	ft_lstadd_back_st(&list, ft_ini_stack(2, 0));
	ft_lstadd_back_st(&list, ft_ini_stack(3, 0));
	ft_lstadd_back_st(&list, ft_ini_stack(1, 0));
	write(1, "2", 1);
	printf("%d", compute_disorder(list));
}
