/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:50:17 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/22 11:10:12 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (lst);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
/*
int	main(void)
{
	t_list	*uno ;
	t_list	*lst ;
	t_list	*dos;
	t_list	*tres;
	t_list	*last;

	lst = ft_lstnew("cero");
	uno = ft_lstnew("uno");
	dos = ft_lstnew("dos");
	tres = ft_lstnew("tres");
	lst->next = uno;
	uno->next = dos;
	dos->next = tres;
	tres->next = NULL;

	last = ft_lstlast(lst);
	printf ("%s", (char *) last->content);
}*/