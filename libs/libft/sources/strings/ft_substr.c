/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Creates allocated string from start to len of s.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_length;
	char	*s_start;
	char	*new_string_start;
	char	*new_string;

	if (s == NULL)
		return (NULL);
	new_string_start = ft_salloc(sizeof(char) * (len + 1));
	new_string = new_string_start;
	s_length = ft_strlen(s);
	s_start = (char *)s;
	s += start;
	while ((size_t)(s - s_start) < s_length && len--)
		*new_string++ = *s++;
	*new_string = '\0';
	return (new_string_start);
}
