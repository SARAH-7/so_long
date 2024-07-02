/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:56:00 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 17:56:42 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = next_node;
	}
	*lst = NULL;
}
