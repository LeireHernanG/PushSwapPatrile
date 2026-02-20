/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:55 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 15:46:35 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

typedef struct s_stacks
{
    int         value;
	int			*content;
	struct s_list	*next;
}					t_stacks;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);

int ft_sb(t_stacks **a);
int ft_sb(t_stacks **b);
int	ft_ss(t_stacks **a, t_stacks **b);
int ft_pa(t_stacks **a, t_stacks **b);
int ft_pb(t_stacks **b);
#endif