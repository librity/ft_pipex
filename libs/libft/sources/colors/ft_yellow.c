/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yellow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:25:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in yellow.
*/
void	ft_yellow(char *str)
{
	ft_putstr(Y);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in yellow followed by an endline.
*/
void	ft_yellow_endl(char *str)
{
	ft_putstr(Y);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold yellow.
*/
void	ft_yellowb(char *str)
{
	ft_putstr(YB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold yellow followed by an endline.
*/
void	ft_yellowb_endl(char *str)
{
	ft_putstr(YB);
	ft_putstr(str);
	ft_putendl(RC);
}
