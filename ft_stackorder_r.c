/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:49 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/25 13:17:30 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_stack **a)
{
	t_stack	*position1;
	t_stack	*lastposition;

	if (!a || !*a)
		return (0);
	position1 = *a;
	lastposition = *a;
	while (lastposition->next)
		lastposition = lastposition->next;
	*a = position1->next;
	lastposition->next = position1;
	position1->next = NULL;
	write(1, "ra\n", 3);
	return (1);
}

int	ft_rb(t_stack **b)
{
	t_stack *position1;
	t_stack *lastposition;

	if (!b || !*b)
		return (0);
	position1 = *b;
	lastposition = *b;
	while (lastposition->next)
		lastposition = lastposition->next;
	*b = position1->next;
	lastposition->next = position1;
	position1->next = NULL;
	write(1, "rb\n", 3);
	return (1);
}