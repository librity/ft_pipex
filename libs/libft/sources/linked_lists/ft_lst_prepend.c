/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:57:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Creates a node and appends it to the beginning of a linked list.
*/
void	ft_lst_prepend(t_list **lst, void *content)
{
	t_list	*new;

	if (lst == NULL || *lst == NULL)
		return ;
	new = ft_lstnew_safe(content);
	ft_lstadd_front(lst, new);
}
