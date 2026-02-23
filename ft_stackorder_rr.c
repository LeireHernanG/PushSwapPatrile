/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:51 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/19 11:41:52 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rra(t_stacks **a)
{
    t_stacks *lastposition;
    t_stacks *new;
    if(!a || !*a)
        return(0);
    lastposition = *a;
    while (lastposition->next)
    {
        new = lastposition;
        lastposition = lastposition->next;
    }
    lastposition -> next = *a;
    *a = lastposition;
    return (1);
}

int ft_rrb(t_stacks **b)
{
    t_stacks *lastposition;
    t_stacks *new;
    if(!b || !*b)
        return(0);
    lastposition = *b;
    while (lastposition->next)
    {
        new = lastposition;
        lastposition = lastposition->next;
    }
    lastposition -> next = *b;
    *b = lastposition;
    return (1);
}

intft_rrr(t_stacks *a, t_stacks *b)
{
    ft_rra(a);
    ft_rrb(b);
    return(1);
}