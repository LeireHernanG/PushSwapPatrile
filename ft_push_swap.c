/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:40:13 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/23 17:49:12 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		algorithm;
	t_stack	 *stackA;

	if (argc <= 1)
		return (1);
	algorithm = control_errors(argc, argv);
	if (algorithm == 0)
		return (1);
	stackA = fill_stack(argc, argv);
	return (0);
}