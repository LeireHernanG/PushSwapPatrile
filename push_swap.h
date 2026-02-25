/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:55 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/25 13:37:05 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				position;
	int				content;
	struct s_stack	*next;
}					t_stack;

void				ft_lstadd_back_st(t_stack **lst, t_stack *new);
t_stack				*ft_ini_stack(int num, int pos);
t_stack				*ft_lstlast_st(t_stack *lst);
int					ft_lstsize_st(t_stack *lst);

int					control_errors(int argc, char **argv);
void				free_mat(char **matrix);
t_stack				*fill_stack(int argc, char **argv);

int					ft_sa(t_stack **a);
int					ft_sb(t_stack **b);
int					ft_ss(t_stack **a, t_stack **b);
int					ft_pa(t_stack **a, t_stack **b);
int					ft_pb(t_stack **a, t_stack **b);
int					ft_ra(t_stack **a);
int					ft_rb(t_stack **b);
int					ft_rra(t_stack **a);
int					ft_rrb(t_stack **b);
int					ft_rrr(t_stack *a, t_stack *b);

int									ft_buble_sort(t_stack **a);
int									ft_radix(t_stack **a, t_stack **b);
int 								ft_max_bits(int size);
int									ft_index(t_stack *a);
#endif