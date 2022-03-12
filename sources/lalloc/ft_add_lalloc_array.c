/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lalloc_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 19:59:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_add_lalloc_array(t_list **lalloc, void **pointer)
{
	if (pointer == NULL)
		return ;
	ft_add_lalloc(lalloc, pointer);
	while (*pointer != NULL)
	{
		ft_add_lalloc(lalloc, *pointer);
		pointer++;
	}
}
