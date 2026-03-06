/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:55 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/06 17:20:47 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				position;
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
typedef struct s_totalmoves
{
	int				sa;
	int				sb;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}					t_totalmoves;

void				ft_lstadd_back_st(t_stack **lst, t_stack *new);
t_stack				*ft_ini_stack(int num, int pos);
t_totalmoves		*ft_ini_total_moves(void);
t_stack				*ft_lstlast_st(t_stack *lst);
int					ft_lstsize_st(t_stack *lst);
void				ft_lstclear_st(t_stack **lst);

int					ft_rightorder(t_stack *a);
int					control_errors(int argc, char **argv);
void				free_mat(char **matrix);
int					fill_stack(int argc, char **argv, t_stack **stack);
float				compute_disorder(t_stack *stack);
void				ft_set_zero(t_stack **a);
int					ft_sqrt(int nb);
void				ft_benchmark(int fd, int algorithm,
						t_totalmoves *totalmoves, float disorder);
int					ft_sa(t_stack **a, t_totalmoves **moves);
int					ft_sb(t_stack **b, t_totalmoves **moves);
int					ft_ss(t_stack **a, t_stack **b);
int					ft_pa(t_stack **a, t_stack **b, t_totalmoves **moves);
int					ft_pb(t_stack **a, t_stack **b, t_totalmoves **moves);
int					ft_ra(t_stack **a, t_totalmoves **moves);
int					ft_rb(t_stack **b, t_totalmoves **moves);
int					ft_rra(t_stack **a, t_totalmoves **totalmoves);
int					ft_rrb(t_stack **b, t_totalmoves **totalmoves);
int					ft_rrr(t_stack *a, t_stack *b);

int					ft_radix(t_stack **a, t_totalmoves **totalmoves);
void				ft_chunkorder(t_stack **a, t_totalmoves **totalmoves);
int					ft_adaptive(t_stack **a, t_totalmoves **totalmoves);
int					ft_simpleorder(t_stack **a, t_totalmoves **totalmoves);
int					ft_fivenum(t_stack **a, t_totalmoves **totalmoves);

#endif
