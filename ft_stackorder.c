/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:38:39 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/09 17:21:16 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	ft_pa(int *a, int *b)
{
	int	i;

	i = 0;
	if (!a || !b)
		return (0);
	b[i] = a[i];
	while (a[i])
	{
		a[i] = a[i + 1];
		i++;
	}
	return (*a);
}

int	ft_pb(int *a, int *b)
{
	int	i;

	i = 0;
	if (!a || !b)
		return (0);
	a[i] = b[i];
	while (b[i])
	{
		b[i] = b[i + 1];
		i++;
	}
	return (*b);
}
