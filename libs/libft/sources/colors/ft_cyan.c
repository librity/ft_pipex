/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:28:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in cyan.
*/
void	ft_cyan(char *str)
{
	ft_putstr(C);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in cyan followed by an endline.
*/
void	ft_cyan_endl(char *str)
{
	ft_putstr(C);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold cyan.
*/
void	ft_cyanb(char *str)
{
	ft_putstr(CB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold cyan followed by an endline.
*/
void	ft_cyanb_endl(char *str)
{
	ft_putstr(CB);
	ft_putstr(str);
	ft_putendl(RC);
}
