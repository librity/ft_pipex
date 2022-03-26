/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:54:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Creates an allocated string joining free_me with dont_free_me,
** then frees free_me.
*/
char	*ft_strjoin_free(char *free_me, char const *dont_free_me)
{
	char	*new_string;

	new_string = ft_strjoin(free_me, dont_free_me);
	free(free_me);
	return (new_string);
}
