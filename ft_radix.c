/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernan- <lhernan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:32:57 by lhernan-          #+#    #+#             */
/*   Updated: 2026/02/27 14:25:53 by lhernan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//funcion para normalizar
void     ft_index(t_stack **a)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     max;

    max = ft_lstsize_st(*a) -1;
    tmp = *a;
    while (tmp)
    {
        tmp->position = 0;
        tmp=tmp->next;
    }
    while(max >= 0)
    {
        tmp = *a;
        while (tmp->position != 0)
            tmp = tmp->next;
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->content < tmp2->content && tmp2->position == 0)
                tmp = tmp2;
            tmp2 = tmp2->next;
        }
        tmp->position = max--;
    }
} 
int ft_radix(t_stack **a)
{
    t_stack *b;
    t_stack *tmp;
    t_stack *stackB;
    int bit;
    int size;
    int bitmax;
    int i;
    
    i = 0;
    bit = 0;
    tmp = *a;
    size = ft_lstsize_st(*a) - 1;
    bitmax = ft_max_bits(size);
    ft_index(a);
    stackB = *a;
     write(1,"\n\n",2);
	while (stackB)
	{
		printf("%d\n", stackB->position);
		stackB = stackB->next;
	}
    printf(":%d\n", bitmax);
    while (bit <= bitmax)
    {
        tmp = *a;
        while(i <= size)
        {
            if (!((tmp->position >> bit) &1))
                ft_pb(a, &b);
            else
                ft_ra(a);
            tmp = *a;
            i++;
        }
        while(b)
            ft_pa(a,&b);
        bit++;
    }
    return (0);
}
int ft_max_bits(int size)
{
    int bits;
    int max;

    if (size < 1)
        return (0);
    bits = 0;
    max = size - 1;
    while (max > 0)
    {
        bits++;
        max >>= 1;
    }
    return (bits);
}

 int main(int argc, char **argv)
{
    int size;
    int max;
	int indi;
	int i;
	t_stack *a;
    t_stack *stackB;

    a = fill_stack(argc, argv);
    size = ft_lstsize_st(a);
	
	ft_radix(&a);
	stackB = a;
     write(1,"\n\n",2);
	while (stackB)
	{
		printf("%d\n", stackB->content);
		stackB = stackB->next;
	}
    return (0);
} 
/*
int ft_radix(t_stack **a, t_stack **b)
{
    int size_a;
    int index;
    int i;

    index = 0;
    i = 0;


    //OPCION 1
    //Seria contar el numero de digitos ddel numero maximo,ej: si tengo 55,1,464, seria 3,y tendriamos que sumarle 1 para saber cuantas veces hariamos el proceso
    // el stack B seria de 10,del 0-9 pq estan en base decimal,irimaos recorriend el stack A comprobando el ultimo dihito de cada numero y pasandolo al B,ej: el 1 iria al indice 1 del stackB,
    //el 55 iria al indice 5 y el 464 al 4. Una vez pasado la primera ronda se vuelven a pasar al sstack A en el orden del indice, quedando 4 55 y 464, en la siguiente ronda en cuyo caso que no estuviera ordenado
    // se pasaria a pasarlo en el stack B comparando con el penultimo digito y asi hasta que estuvieran todos ordenados
   //OPCION 1.1.NEGATIVOS
    //OJO : tambien hay que tener en cuenta los negativos,priemro se deviden en dos arreglos ,uno <0 y otro >0 y aplicariamos nuestro radix,pero los negativos habra que pasarlos a positivos
    //ademas los negativos tendremos que insertarlos en orden inverso,ya que al ordenar nuestro arreglo de negativos sera algo asi: -635,-8691 -26 pero a la hora de hacer el radix cmo he explicado antes se ordenaria asi:-26,-635 y -869
    //EL paso final seria, pasar el arreglo de los negativs a - y de forma inversa al stack A de vuelta,y luego el stack de positivos en orden como estan
    //OPCION 1.2.NEGATIVOS
    //Seria hacer lo mismo que la primera opcion sin negativos pero en vez de un stack de B con 9 seria del -9 al 9
    //OPCION 2
    //pasar al indice, si tengo 3 2 1, el indice seria el 1->0, el 2->1 y el 3->2. de ahi miro lo sbites maximos para saber cuantas veces itero
    // luego con el bitmax >> 1 voy avanzando y comparando con el &1 == 0 lo muevo a stack b,entonces luego miro l siguiente bit y quedara todo como 000,001,010...
    
    size_a = ft_lstsize_st(*a);
    while(size_a > i)
    {
        if((*a)->content == 0)
            ft_pb(a, b);
        else
            ft_ra(a);
        i++;
    }
    return (1);
} */
