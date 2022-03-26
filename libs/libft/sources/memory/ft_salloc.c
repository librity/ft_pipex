/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_salloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:57:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Safe malloc: if allocation fails it terminates the program.
*/
void	*ft_salloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (pointer == NULL && (size > 0))
	{
		ft_putstr_fd(MALLOC_ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
	return (pointer);
}
