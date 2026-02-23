/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:38 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 14:08:34 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_pa(t_stacks **a, t_stacks **b)
{
    t_stacks *temp;

    if (!a || !b || !*b)
        return (0);
    temp = *b;
	*b = *b -> next;
	temp -> next = *a;
	*a = temp;
	
    return (1);
}

int ft_pb(t_stacks **a, t_stacks **b)
{
    t_stacks *temp;

    if (!a || !b || !*a)
        return (0);
    temp = *a;
	*a = *a -> next;
	temp -> next = *b;
	*b = temp;
	
    return (1);
}