/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:26:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Removes set from beginning and end of s1.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	trimmed_end = ft_strlen(s1);
	while (trimmed_end && ft_strchr(set, s1[trimmed_end]))
		trimmed_end--;
	return (ft_substr(s1, 0, trimmed_end + 1));
}
