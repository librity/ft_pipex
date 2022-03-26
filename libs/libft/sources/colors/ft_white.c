/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_white.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:29:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in white.
*/
void	ft_white(char *str)
{
	ft_putstr(W);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in white followed by an endline.
*/
void	ft_white_endl(char *str)
{
	ft_putstr(W);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold white.
*/
void	ft_whiteb(char *str)
{
	ft_putstr(WB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold white followed by an endline.
*/
void	ft_whiteb_endl(char *str)
{
	ft_putstr(WB);
	ft_putstr(str);
	ft_putendl(RC);
}
