/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:08:51 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/06 18:14:55 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isbigthanbotton(t_stack **a, t_totalmoves **totalmoves, int len,
		int *ord)
{
	t_stack	*temp2;
	t_stack	*temp;
	int		mov;
	int		i;

	temp = *a;
	mov = 0;
	while (*ord != mov && *ord > 0 && (len - 1) > *ord)
	{
		i = 0;
		temp2 = *a;
		while (++i < (len - mov))
			temp2 = temp2->next;
		if (temp->content > (temp2->content))
			mov++;
		else
		{
			ft_rra(a, totalmoves);
			ft_sa(a, totalmoves);
			(*ord)--;
			break ;
		}
	}
	return (0);
}

int	ft_simpleorder(t_stack **a, t_totalmoves **totalmoves)
{
	int		ord;
	int		len;
	t_stack	*temp;

	len = ft_lstsize_st(*a);
	ord = 0;
	while (len > ord && !ft_rightorder(*a))
	{
		temp = *a;
		ft_isbigthanbotton(a, totalmoves, len, &ord);
		if (temp->content < temp->next->content || (len - 1) == ord)
		{
			ord++;
			ft_ra(a, totalmoves);
		}
		else
			ft_sa(a, totalmoves);
	}
	return (0);
}
