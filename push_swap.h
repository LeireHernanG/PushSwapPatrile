/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:55 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 17:18:02 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>

typedef struct s_stacks
typedef struct s_stack
{
    int         value;
	int			*content;
	struct s_stacks	*next;
}					t_stacks;
	int				position;
	int				content;
	struct s_stack	*next;
}					t_stack;

void				ft_lstadd_back_st(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_stack				*ft_ini_stack(int num, int pos);
t_stack				*ft_lstlast_st(t_stack *lst);

int ft_sb(t_stacks **a);
int ft_sb(t_stacks **b);
int	ft_ss(t_stacks **a, t_stacks **b);
int ft_pa(t_stacks **a, t_stacks **b);
int ft_pa(t_stacks **a, t_stacks **b);
int ft_pb(t_stacks **a, t_stacks **b);
int ft_rra(t_stacks **a);
int ft_rrb(t_stacks **b);
int ft_rrr(t_stacks *a, t_stacks *b);
#endif