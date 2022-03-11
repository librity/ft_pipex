/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 18:58:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
** Concatenates src to destination, writing size bytes at most.
** Returns initial length of dst plus length of src for truncation detection.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destination_length;

	destination_length = ft_strlen(dst);
	if (size <= destination_length)
		return (size + ft_strlen(src));
	while (*src && destination_length < size - 1)
		*(dst + destination_length++) = *src++;
	*(dst + destination_length) = '\0';
	return (destination_length + ft_strlen(src));
}
