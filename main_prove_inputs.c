#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
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
	stackA = fill_stack(argc, argv);
	stackB = stackA;
	while (stackB)
	{
		printf("%d\n", stackB->content);
		stackB = stackB->next;
	}
	ft_buble_sort(&stackA);
	return (0);
}