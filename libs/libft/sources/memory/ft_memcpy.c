/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Copies the n bytes after src to dest. Not overlap safe.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*source_cast;
	unsigned char	*destination_cast;

	if (dest == NULL && src == NULL)
		return (dest);
	source_cast = (unsigned char *)src;
	destination_cast = (unsigned char *)dest;
	while (n--)
	{
		*destination_cast = *source_cast;
		destination_cast++;
		source_cast++;
	}
	return (dest);
}
