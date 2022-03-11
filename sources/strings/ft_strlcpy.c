/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 02:46:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 18:58:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
** Copy first size chars from src to dst. Not overlap safe.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char			current_char;
	unsigned int	iterator;

	if (src == NULL)
		return (0);
	if (size > 0)
	{
		iterator = 0;
		current_char = src[iterator];
		while (current_char != '\0' && iterator < (size - 1))
		{
			dst[iterator] = current_char;
			iterator++;
			current_char = src[iterator];
		}
		dst[iterator] = '\0';
	}
	return (ft_strlen(src));
}
