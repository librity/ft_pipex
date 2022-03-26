/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lalloc_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Appends an allocated array to a linked list.
*/
void	ft_add_lalloc_array(t_list **lalloc, void **pointers)
{
	if (pointers == NULL)
		return ;
	ft_add_lalloc(lalloc, pointers);
	while (*pointers != NULL)
	{
		ft_add_lalloc(lalloc, *pointers);
		pointers++;
	}
}
