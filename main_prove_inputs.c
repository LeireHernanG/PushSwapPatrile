/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prove_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:22:38 by lhernan-          #+#    #+#             */
/*   Updated: 2026/03/02 19:27:08 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		algorithm;
	t_stack	*stacka;
	t_stack	*stackb;

	if (argc <= 1)
	{
		printf("Pocos argumentos");
		return (1);
	}
	algorithm = control_errors(argc, argv);
	if (algorithm == 0)
	{
		printf("inputs incorrectos");
		return (1);
	}
	stacka = fill_stack(argc, argv);
	stackb = stacka;
	while (stackb)
	{
		printf("%d\n", stackb->content);
		stackb = stackb->next;
	}
	ft_chunkorder(&stacka);
	stackb = stacka;
	printf("\n\n");
	while (stackb)
	{
		printf("%d\n", stackb->content);
		stackb = stackb->next;
	}
	return (0);
}

// MAIN PARA VER EL MAXIMO DE ITERACIONES EN BITS
/* int main(int argc, char **argv)
{
	int size;
	int max;
	int indi;
	int i;
	t_stack **a;

	*a = fill_stack(argc, argv);
	size = ft_lstsize_st(*a);
	printf("Size:%d", size);
	max = ft_max_bits(size);
	printf("\nMax:%d", max);
	indi = ft_index(*a);
	while(i <= max)
	{
		printf("\nIndice:%d", max);
		i++;
	}
	return (0);
} */
