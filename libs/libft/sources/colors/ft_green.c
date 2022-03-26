/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:23:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:25:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in green.
*/
void	ft_green(char *str)
{
	ft_putstr(G);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in green followed by an endline.
*/
void	ft_green_endl(char *str)
{
	ft_putstr(G);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold green.
*/
void	ft_greenb(char *str)
{
	ft_putstr(GB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold green followed by an endline.
*/
void	ft_greenb_endl(char *str)
{
	ft_putstr(GB);
	ft_putstr(str);
	ft_putendl(RC);
}
