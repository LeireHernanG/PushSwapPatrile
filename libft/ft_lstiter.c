/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:36:38 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/26 13:31:38 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	f(void *n)
{
	(chat *)nmake fclean = "hola";
}

int	main(void)
{
	t_list	*lst;
	t_list	*temp;

	lst = malloc(sizeof(t_list));
	lst->content = ft_strdup("cero");
	lst->next = malloc(sizeof(t_list));
	lst->next->content = ft_strdup("uno");
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->content = ft_strdup("dos");
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->content = ft_strdup("tres");
	lst->next->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->next->content = ft_strdup("cuatro");
	lst->next->next->next->next->next = NULL;

	temp = lst;
	while (temp != NULL)
	{
		printf("%s\n", (char *) temp->content);
		temp = temp->next;
	}
	printf("\n");
	ft_lstiter(lst, f);
	temp = lst;
	while (temp != NULL)
	{
		printf("%s\n", (char *) temp->content);
		temp = temp->next;
	}
}
*/