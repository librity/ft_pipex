/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_int_commas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:46:58 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 22:19:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Skips '+'ses and '-'ses, then skips ASCII numbers.
*/
char	*ft_skip_int_commas(char *str)
{
	str = ft_skip_int(str);
	str = ft_skip_commas(str);
	return (str);
}
