/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:38 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/25 13:15:49 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !b || !*b)
		return (0);
	temp = *b;
	*b = (*b)->next;
	if (*a)
		temp->next = *a;
	else
		temp->next = NULL;
	*a = temp;
	write(1, "pa\n", 3);
	return (1);
}

int	ft_pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!a || !b || !*a)
		return (0);
	temp = *a;
	*a = (*a)->next;
	if (*b)
		temp->next = *b;
	else
		temp->next = NULL;
	*b = temp;
	write(1, "pb\n", 3);
	return (1);
}