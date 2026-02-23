/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:55 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/23 13:27:38 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>

typedef struct s_stack
{
	int				position;
	int				content;
	struct s_stacks	*next;
}					t_stack;

void				ft_lstadd_back_st(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_stack				*ft_ini_stack(int num, int pos);
t_stack				*ft_lstlast_st(t_stack *lst);

int					ft_sb(t_stack **a);
int					ft_sb(t_stack **b);
int					ft_ss(t_stack **a, t_stack **b);
int					ft_pa(t_stack **a, t_stack **b);
int					ft_pa(t_stack **a, t_stack **b);
int					ft_pb(t_stack **a, t_stack **b);
int					ft_rra(t_stack **a);
int					ft_rrb(t_stack **b);
int					ft_rrr(t_stack *a, t_stack *b);
#endif