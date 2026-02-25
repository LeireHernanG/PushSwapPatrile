/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:39 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/25 12:56:06 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_stack **a)
{
	t_stack	*stack1;
	t_stack	*stack2;

	if (!a || !(*a)->next)
		return (0);
	stack1 = *a;
	stack2 = stack1->next;
	stack1->next = stack2->next;
	stack2->next = stack1;
	*a = stack2;
	write(1, "sa\n", 3);
	return (1);
}

int	ft_sb(t_stack **b)
{
	t_stack	*stack1;
	t_stack	*stack2;

	if (!b || !(*b)->next)
		return (0);
	stack1 = *b;
	stack2 = stack1->next;
	stack1->next = stack2->next;
	stack2->next = stack1;
	*b = stack2;
	write(1, "sb\n", 3);
	return (1);
}

int	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
	write(1, "ss\n", 3);
	return (1);
}
