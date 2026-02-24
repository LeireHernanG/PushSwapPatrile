/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:45:49 by pmieres-          #+#    #+#             */
/*   Updated: 2026/02/23 19:08:27 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mat(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	is_not_correct(char *param)
{
	int		len;
	char	**nums;
	int		i;
	int		j;

	i = 0;
	nums = ft_split(param, ' ');
	while (nums[i])
	{
		len = ft_strlen(nums[i]);
		j = 0;
		while (j < len)
		{
			if (!ft_isdigit(nums[i][j]))
			{
				if (!((nums[i][j] == '-' || nums[i][j] == '+') && nums[i][j + 1]
						&& ft_isdigit(nums[i][j + 1])))
				{
					free_mat(nums);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	free_mat(nums);
	return (0);
}

int	control_errors(int argc, char **argv)
{
	int	algorithm;
	int	i;

	i = 2;
	algorithm = 0;
	if (!ft_strncmp(argv[1], "--simple", ft_strlen(argv[1])))
		algorithm = 1;
	else if (!ft_strncmp(argv[1], "--medium", ft_strlen(argv[1])))
		algorithm = 2;
	else if (!ft_strncmp(argv[1], "--complex", ft_strlen(argv[1])))
		algorithm = 3;
	else if (!ft_strncmp(argv[1], "--adaptive", ft_strlen(argv[1])))
		algorithm = 4;
	if (algorithm == 0)
	{
		i = 1;
		algorithm = 4;
	}
	while (i < argc)
	{
		if (is_not_correct(argv[i]))
			return (0);
		i++;
	}
	return (algorithm);
}

t_stack	*fill_stack(int argc, char **argv)
{
	int		pos;
	char	**nums;
	int		i;
	int		j;
	t_stack	*stack;

	i = 1;
	pos = 0;
	stack = NULL;
	if (argv[1][1] == '-')
		i++;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		j = 0;
		while (nums[j])
		{
			ft_lstadd_back_st(&stack, ft_ini_stack(atoi(nums[j]), pos));
			pos++;
			j++;
		}
		free_mat(nums);
		i++;
	}
	return (stack);
}
