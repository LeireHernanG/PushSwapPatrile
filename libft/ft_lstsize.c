/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:32:50 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/23 11:42:49 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		size;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

/*
int	main(void)
{
	t_list	*uno ;
	t_list	*lst ;
	// t_list	*dos;
	// t_list	*tres;
	//int		i = 158;

	lst = ft_lstnew("cero");
	uno = ft_lstnew("uno");
	// dos = ft_lstnew("dos");
	// tres = ft_lstnew("tres");
	lst->next = uno;
	uno->next = NULL;
	// dos->next = tres;
	// tres->next = NULL;

	printf ("%d", ft_lstsize(lst));

}
*/