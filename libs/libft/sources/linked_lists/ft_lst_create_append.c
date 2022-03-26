/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create_append.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** If not initialized, creates list with allocates pointer.
** If initialized, appends allocated pointer to list.
*/
void	ft_lst_create_append(t_list **list, void *pointer)
{
	if (*list == NULL)
	{
		*list = ft_lstnew_safe(pointer);
		return ;
	}
	ft_lst_append(list, pointer);
}
