/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:02:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/19 21:45:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Creates a new linked list and runs f on all its contents.
** If it fails in creating a node it clears the list with del.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_map;

	if (lst == NULL)
		return (NULL);
	list_map = ft_lstnew(f(lst->content));
	if (list_map == NULL)
	{
		ft_lstclear(&list_map, del);
		return (NULL);
	}
	list_map->next = ft_lstmap(lst->next, f, del);
	return (list_map);
}
