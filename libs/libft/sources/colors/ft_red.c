/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:25:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in red.
*/
void	ft_red(char *str)
{
	ft_putstr(R);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in red followed by an endline.
*/
void	ft_red_endl(char *str)
{
	ft_putstr(R);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold red.
*/
void	ft_redb(char *str)
{
	ft_putstr(RB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold red followed by an endline.
*/
void	ft_redb_endl(char *str)
{
	ft_putstr(RB);
	ft_putstr(str);
	ft_putendl(RC);
}
