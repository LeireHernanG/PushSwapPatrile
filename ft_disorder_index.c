/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:42:33 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/05 14:29:57 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*nod;
	t_stack	*list;

	if (!stack)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	list = stack;
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

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i <= nb)
		i++;
	return (i - 1);
}

void	ft_set_zero(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->position = 0;
		tmp = tmp->next;
	}
}
