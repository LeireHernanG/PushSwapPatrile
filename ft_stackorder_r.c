/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:49 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/23 18:24:08 by pmieres-         ###   ########.fr       */
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
	return (1);
}

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
	position1 = NULL;
	lastposition->next = position1;
	return (1);
}