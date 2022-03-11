/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:02:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 15:13:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
** Creates a new linked list and runs f on all its contents or dies trying.
*/
t_list	*ft_lstmap_safe(t_list *lst, void *(*f)(void *))
{
	t_list	*list_map;

	if (lst == NULL)
		return (NULL);
	list_map = ft_lstnew_safe(f(lst->content));
	list_map->next = ft_lstmap_safe(lst->next, f);
	return (list_map);
}
