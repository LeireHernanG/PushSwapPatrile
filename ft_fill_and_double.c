/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_and_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:38:01 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/03 18:24:27 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_double(t_stack **stack, char *str, char **nums)
{
	int		num;
	t_stack	*temp;

	num = atoi(str);
	temp = *stack;
	while (temp)
	{
		if (temp->content == num)
		{
			ft_lstclear_st(stack);
			free_mat(nums);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	fill_stack(int argc, char **argv, t_stack **stack)
{
	int		pos;
	char	**nums;
	int		i;
	int		j;

	i = 0;
	pos = -1;
	while (++i < argc)
	{
		nums = ft_split(argv[i], ' ');
		j = -1;
		while (nums[++j])
		{
			if (!(nums[j][1] && nums[j][1] == '-'))
			{
				if (ft_is_double(stack, nums[j], nums))
					return (1);
				ft_lstadd_back_st(stack, ft_ini_stack(atoi(nums[j]), ++pos));
			}
		}
		free_mat(nums);
	}
	return (0);
}
