/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:39 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/19 11:47:59 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(int *a, int *b)
{
	int	i;
	int	*temp;

	temp = NULL;
	i = 0;
	if (!a || !b)
		return (0);
	temp[i] = a[i];
	a[i] = a[i + 1];
	a[i] = temp[i];
	return (*a);
}

int	ft_sb(int *a, int *b)
{
	int	i;
	int	*temp;

	temp = NULL;
	i = 0;
	if (!a || !b)
		return (0);
	temp[i] = b[i];
	b[i] = b[i + 1];
	b[i] = temp[i];
	return (*b);
}

int	ft_ss(int *a, int *b)
{
	ft_sa(a, b);
	ft_sb(a, b);
	return (0);
}

