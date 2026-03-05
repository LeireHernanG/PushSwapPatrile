/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:58:35 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/26 12:20:45 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
int	main(void)
{
	t_list	*uno ;
	t_list	*lst ;
	t_list	*dos;
	t_list	*tres;
	t_list	*cuatro;
	//t_list	*temp;

	lst = ft_lstnew("cero");
	uno = ft_lstnew("uno");
	dos = ft_lstnew("dos");
	tres = ft_lstnew("tres");
	cuatro = ft_lstnew("cuatro");
	// lst->next = uno;
	// uno->next = dos;
	// dos->next = NULL;
	// tres->next = NULL;

	lst = NULL;
    ft_lstadd_back(&lst, uno);
    ft_lstadd_back(&lst, dos);
    ft_lstadd_back(&lst, tres);
    ft_lstadd_back(&lst, cuatro);

	while (lst)
    {
        printf("%s", (char *) lst->content);
        lst = lst->next;
    }

	printf("\n");
	// ft_lstadd_back(&lst, tres);
	// temp = lst;
	// while (temp != NULL)
	// {
	// 	printf("%s", (char *) temp->content);
	// 	temp = temp->next;
	// }
}*/