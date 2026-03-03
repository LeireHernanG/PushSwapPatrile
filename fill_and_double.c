/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:38:01 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/03 14:16:31 by pmieres-         ###   ########.fr       */
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

t_stack	*fill_stack(int argc, char **argv)
{
	int		pos;
	char	**nums;
	int		i;
	int		j;
	t_stack	*stack;

	i = 0;
	pos = -1;
	stack = NULL;
	while (++i < argc)
	{
		nums = ft_split(argv[i], ' ');
		j = -1;
		while (nums[++j])
		{
			if (!(nums[j][1] && nums[j][1] == '-'))
			{
				if (ft_is_double(&stack, nums[j], nums))
					return (NULL);
				ft_lstadd_back_st(&stack, ft_ini_stack(atoi(nums[j]), ++pos));
			}
		}
		free_mat(nums);
	}
	return (stack);
}
