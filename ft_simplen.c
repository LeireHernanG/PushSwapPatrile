/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:08:51 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/09 13:11:35 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	ft_isbigthanbotton(t_stack **a, t_totalmoves **totalmoves, int len,
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
	t_stack	*stackb;

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
	stackb = *a;
	while (stackb)
	{
		printf("%d\n", stackb->content);
		stackb = stackb->next;
	}
	return (0);
} */
//  static int	is_max(t_stack *a)
// {
// 	t_stack	*index;
// 	int		max;

// 	max = 0;
// 	index = (a)->next;
// 	while (index && (a)->content < index->content)
// 	{
// 		max++;
// 		index = index->next;
// 	}
// 	if (max == ft_lstsize_st(a) - 1)
// 		return (1);
// 	else
// 		return (0);
// }

// static int	ft_max_is_last(t_stack **a, int len)
// {
// 	int		max;
// 	t_stack	*last;
// 	t_stack	*index;

// 	max = 0;
// 	index = *a;
// 	last = ft_lstlast_st(*a);
// 	while (index->next)
// 	{
// 		if (last->content < index->content)
// 			max++;
// 		index = index->next;
// 	}
// 	if (max == len)
// 		return (1);
// 	else
// 		return (0);
// }

// static int	ft_maxorder(t_stack **a, t_stack **b, t_totalmoves **totalmoves)
// {
// 	int	len;
// 	int	max;

// 	len = ft_lstsize_st(*a) - 1;
// 	max = 0;
// 	if (len != 0 && ft_max_is_last(a, len))
// 	{
// 		ft_rra(a, totalmoves);
// 		ft_pb(a, b, totalmoves);
// 		return (0);
// 	}
// 	if (is_max(*a))
// 		ft_pb(a, b, totalmoves);
// 	else if (is_max((*a)->next))
// 	{
// 		ft_sa(a, totalmoves);
// 		ft_pb(a, b, totalmoves);
// 	}
// 	else
// 		ft_ra(a, totalmoves);
// 	return (0);
// }

// int	ft_simpleorder(t_stack **a, t_totalmoves **totalmoves)
// {
// 	t_stack	*b;
// 	t_stack *stackb;
// 	b = NULL;
// 	while (*a)
// 		ft_maxorder(a, &b, totalmoves);
// 	while (b)
// 		ft_pa(a, &b, totalmoves);
// 	stackb = *a;
// 	while (stackb)
// 	{
// 		printf("%d\n", stackb->content);
// 		stackb = stackb->next;
// 	}
// 	return (0);
// }

 static int	is_max(t_stack *a)
{
	t_stack	*index;
	int		max;

	max = 0;
	index = (a)->next;
	while (index && (a)->content > index->content)
	{
		max++;
		index = index->next;
	}
	if (max == ft_lstsize_st(a) - 1)
		return (1);
	else
		return (0);
}


static int	ft_maxorder(t_stack **a, t_stack **b, t_totalmoves **totalmoves)
{
	int	len;
	int	max;

	len = ft_lstsize_st(*a) - 1;
	max = 0;
	if (is_max(*a))
		ft_pb(a, b, totalmoves);
	else
		ft_ra(a, totalmoves);
	return (0);
}

int	ft_simpleorder(t_stack **a, t_totalmoves **totalmoves)
{
	t_stack	*b;
	t_stack *stackb;
	b = NULL;
	
	while (*a)
		ft_pb(a, &b, totalmoves);
	while (b)
		ft_maxorder(&b, a, totalmoves);
	 stackb = *a;
	while (stackb)
	{
		printf("%d\n", stackb->content);
		stackb = stackb->next;
	} 
	return (0);
}  
