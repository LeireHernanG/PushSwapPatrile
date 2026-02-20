/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:42:33 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 15:38:06 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_st *stacka)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	t_st	*nod;
	t_st	*list;

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
	t_list	*list;
	int	a;

	a = 4;
	ft_lstadd_back(&list, ft_lstnew(&a));
	ft_lstadd_back(&list, ft_lstnew(2));
	ft_lstadd_back(&list, ft_lstnew(3));
	ft_lstadd_back(&list, ft_lstnew(1));
	printf("%d", compute_disorder(list));
}
