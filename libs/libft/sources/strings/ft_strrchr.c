/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Returns last occurence of char c in string or NULL.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*s_end;

	s_end = ft_strchr(s, '\0');
	while (*s_end != (char)c)
		if (s_end-- == s)
			return (NULL);
	return ((char *)s_end);
}
