/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:26:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in blue.
*/
void	ft_blue(char *str)
{
	ft_putstr(B);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in blue followed by an endline.
*/
void	ft_blue_endl(char *str)
{
	ft_putstr(B);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold blue.
*/
void	ft_blueb(char *str)
{
	ft_putstr(BB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold blue followed by an endline.
*/
void	ft_blueb_endl(char *str)
{
	ft_putstr(BB);
	ft_putstr(str);
	ft_putendl(RC);
}
