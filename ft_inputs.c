/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:45:49 by pmieres-          #+#    #+#             */
/*   Updated: 2026/03/05 15:52:01 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	select_algorithm(char *argv)
{
	if (!ft_strncmp(argv, "--simple", 8))
		return (1);
	else if (!ft_strncmp(argv, "--medium", 8))
		return (2);
	else if (!ft_strncmp(argv, "--complex", 9))
		return (3);
	else if (!ft_strncmp(argv, "--adaptive", 10))
		return (4);
	else
		return (0);
}

static int	ft_is_flag(int *algorithm, char *num, int *bench, int j)
{
	if (!ft_isdigit(num[j]))
	{
		if (*algorithm == 0)
		{
			*algorithm = select_algorithm(num);
			if (*algorithm != 0)
				return (2);
		}
		if (*bench != -1 && !ft_strncmp(num, "--bench", 7))
		{
			*bench = -1;
			return (2);
		}
		if (!((num[0] == '-' || num[0] == '+') && num[1] && ft_isdigit(num[1])))
			return (1);
	}
	return (0);
}

static int	is_not_correct(char *param, int *algorithm, int *bench)
{
	int		len;
	char	**nums;
	int		i;
	int		j;

	i = -1;
	nums = ft_split(param, ' ');
	while (nums[++i])
	{
		len = ft_strlen(nums[i]);
		j = 0;
		while (j < len)
		{
			if (ft_is_flag(algorithm, nums[i], bench, j) == 2)
				j = len;
			else if (ft_is_flag(algorithm, nums[i], bench, j) == 1)
			{
				free_mat(nums);
				return (1);
			}
			j++;
		}
	}
	free_mat(nums);
	return (0);
}

int	control_errors(int argc, char **argv)
{
	int	algorithm;
	int	bench;
	int	i;

	i = 1;
	bench = 1;
	algorithm = 0;
	while (i < argc)
	{
		if (is_not_correct(argv[i], &algorithm, &bench))
			return (0);
		i++;
	}
	if (algorithm == 0)
		algorithm = 4;
	return (algorithm * bench);
}
