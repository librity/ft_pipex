/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:54:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 18:58:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
** Creates an allocated string joining free_me with free_me_too,
** then frees free_me and free_me_too.
*/
char	*ft_strjoin_free_free(char *free_me, char *free_me_too)
{
	char	*new_string;

	new_string = ft_strjoin(free_me, free_me_too);
	free(free_me);
	free(free_me_too);
	return (new_string);
}
