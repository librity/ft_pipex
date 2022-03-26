/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:56:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 12:27:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** If s1 and s2 are equal returns true; else returns false.
*/
bool	ft_streq(char *s1, char *s2)
{
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (false);
	return (true);
}
