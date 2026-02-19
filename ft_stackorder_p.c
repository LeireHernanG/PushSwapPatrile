/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackorder_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:41:38 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/19 11:41:39 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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