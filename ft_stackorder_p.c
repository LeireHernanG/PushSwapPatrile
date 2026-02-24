/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:38 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/24 13:00:46 by pmieres-         ###   ########.fr       */
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
	temp->next = *a;
	*a = temp;
	//ft_printf("%s","pa");
	return (1);
}

int	ft_pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!a || !b || !*a)
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	//ft_printf("%s","pb");
	return (1);
}