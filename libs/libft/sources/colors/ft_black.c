/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_black.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:22:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 14:25:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Writes str to standard out in black.
*/
void	ft_black(char *str)
{
	ft_putstr(BK);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in black followed by an endline.
*/
void	ft_black_endl(char *str)
{
	ft_putstr(BK);
	ft_putstr(str);
	ft_putendl(RC);
}

/*
** Writes str to standard out in bold black.
*/
void	ft_blackb(char *str)
{
	ft_putstr(BKB);
	ft_putstr(str);
	ft_putstr(RC);
}

/*
** Writes str to standard out in bold black followed by an endline.
*/
void	ft_blackb_endl(char *str)
{
	ft_putstr(BKB);
	ft_putstr(str);
	ft_putendl(RC);
}
