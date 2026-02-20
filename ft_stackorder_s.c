/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:39 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 13:54:37 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sb(t_stacks **a)
{
    t_stacks *stack1;
    t_stacks *stack2;

    if (!a || !(*a)->next)
        return (0);

    stack1 = *a;
    stack2 = stack1->next;

    stack1->next = stack2->next;
    stack2->next = stack1;
    *a = stack2;

    return (0);
}

int ft_sb(t_stacks **b)
{
    t_stacks *stack1;
    t_stacks *stack2;

    if (!b || !(*b)->next)
        return (0);

    stack1 = *b;
    stack2 = stack1->next;

    stack1->next = stack2->next;
    stack2->next = stack1;
    *b = stack2;

    return (0);
}

int	ft_ss(t_stacks **a, t_stacks **b)
{
	ft_sa(a);
	ft_sb(b);
	return (0);
}

