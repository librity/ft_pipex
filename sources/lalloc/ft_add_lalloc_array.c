/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lalloc_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 18:08:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_add_lalloc_array(t_list **alloc, void **pointer)
{
	if (pointer == NULL)
		return ;
	ft_add_lalloc(alloc, pointer);
	while (*pointer != NULL)
	{
		ft_add_lalloc(alloc, *pointer);
		pointer++;
	}
}
