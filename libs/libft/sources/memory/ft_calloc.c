/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Allocates (nmemb * size) bytes of memory memory and sets them all to zero.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*allocated;

	total_size = nmemb * size;
	allocated = ft_salloc(total_size);
	ft_bzero(allocated, total_size);
	return (allocated);
}
