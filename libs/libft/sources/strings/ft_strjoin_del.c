/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:54:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Creates an allocated string joining delete_me with dont_delete_me,
** then deletes delete_me.
*/
char	*ft_strjoin_del(char **delete_me, const char *dont_delete_me)
{
	char	*new_string;

	new_string = ft_strjoin(*delete_me, dont_delete_me);
	ft_strdel(delete_me);
	return (new_string);
}
