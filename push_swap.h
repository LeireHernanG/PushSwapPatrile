/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:55 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/20 16:49:59 by pmieres-         ###   ########.fr       */
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
	struct s_stack	*next;
}					t_stack;

void				ft_lstadd_back_st(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_stack				*ft_ini_stack(int num, int pos);
t_stack				*ft_lstlast_st(t_stack *lst);

int					ft_sa(int *a, int *b);
int					ft_sb(int *a, int *b);
int					ft_ss(int *a, int *b);
int					ft_pa(int *a, int *b);
int					ft_pb(int *a, int *b);
#endif