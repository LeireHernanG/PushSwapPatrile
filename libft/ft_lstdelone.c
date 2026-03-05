/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmieres- <pmieres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:51:43 by pmieres-          #+#    #+#             */
/*   Updated: 2026/01/22 12:31:17 by pmieres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}
/*
void	del(void *nod)
{
	free(nod);
}

int	main(void)
{
	t_list	*dos;

	dos = malloc(sizeof(t_list *));
	dos->content = ft_strdup("hola");
	dos->next = dos;
	ft_lstdelone(dos, del);
}
*/