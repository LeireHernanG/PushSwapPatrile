/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:49 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/19 11:41:50 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_ra(t_stacks **a)
{
    t_stacks *position1;
    t_stacks *lastposition;

    if(!a || !*a)
        return (0);
    position1 = *a;
    lastposition = *a;
    while(lastposition -> next)
        lastposition = lastposition -> next;
    a* = position1-> next;
    lastposition -> next = position1;
    return (1);
}
int    ft_ra(t_stacks **a)
{
    t_stacks *position1;
    t_stacks *lastposition;

    if(!a || !*a)
        return (0);
    position1 = *a;
    lastposition = *a;
    while(lastposition -> next)
        lastposition = lastposition -> next;
    a* = position1-> next;
    position1 = NULL;
    lastposition -> next = position1;
    return (1);
}