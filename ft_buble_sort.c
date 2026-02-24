/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buble_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:17:47 by pmieres-          #+#    #+#             */
/*   Updated: 2026/02/24 16:27:06 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
static int	ft_rightorder(t_stack *a)
{
	while (a->next && a -> content < a->next->content)
	{
		a = a->next;
	}
	if (a->next == NULL)
		return(1);
	return(0);
}
int ft_buble_sort(t_stack **a)
{
	int		order;
	t_stack *stackB;

	order = 1;


	while (order)
	{
		if (ft_rightorder(*a) == 1)
				return (1);
		if ((*a)->content > (*a)->next->content)
		{
			ft_sa(a);
			if (ft_rightorder(*a) == 1)
			{
				write(1,"s\n",2);
				return (1);	
			}
			ft_ra(a);
			if (ft_rightorder(*a) == 1)
			{
				write(1,"ra\n",3);
				return (1);
			}
			write(1,"t\n",2);
		}
		else
		{
			ft_ra(a);
			if (ft_rightorder(*a) == 1)
				return (1);
			write(1,"ra\n",3);
		}
		stackB = *a;
		while (stackB)
		{
			printf("%d\n", stackB->content);
			stackB = stackB->next;
		}
	}
	return (1);
}

