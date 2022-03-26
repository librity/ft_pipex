/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:41:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Like memcpy but overlap safe.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*source_cast;
	unsigned char	*destination_cast;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	if (src < dest)
	{
		source_cast = (unsigned char *)src + n - 1;
		destination_cast = (unsigned char *)dest + n - 1;
		while (n--)
		{
			*destination_cast = *source_cast;
			destination_cast--;
			source_cast--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
