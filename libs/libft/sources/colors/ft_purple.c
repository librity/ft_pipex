/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:27:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in purple.
*/
void	ft_purple(char *str)
{
	ft_putstr(P);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in purple followed by an endline.
*/
void	ft_purple_endl(char *str)
{
	ft_putstr(P);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold purple.
*/
void	ft_purpleb(char *str)
{
	ft_putstr(PB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold purple followed by an endline.
*/
void	ft_purpleb_endl(char *str)
{
	ft_putstr(PB);
	ft_putstr(str);
	ft_putendl(RC);
}
