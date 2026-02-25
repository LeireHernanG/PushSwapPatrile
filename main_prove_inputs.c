#include "push_swap.h"
#include <stdio.h>

/* int	main(int argc, char **argv)
{
	int algorithm;
	t_stack *stackA;
	t_stack *stackB;

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
	printf("%d\n", algorithm);
	stackA = fill_stack(argc, argv);
	stackB = stackA;
	while (stackB)
	{
		printf("%d\n", stackB->content);
		stackB = stackB->next;
	}
	ft_radix(&stackA, &stackB);
	stackB = stackA;
	while (stackB)
	{
		printf("%d\n", stackB->content);
		stackB = stackB->next;
	}
	return (0);
} */

//MAIN PARA VER EL MAXIMO DE ITERACIONES EN BITS
int main(int argc, char **argv)
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
}