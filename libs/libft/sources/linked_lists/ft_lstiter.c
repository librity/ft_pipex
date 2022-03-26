/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Trasverses every node of a linked list while running f on every content.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	f(lst->content);
	if (lst->next == NULL)
		return ;
	ft_lstiter(lst->next, f);
}
