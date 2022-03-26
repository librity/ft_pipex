/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:16:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Maps a double that varies between a range into a target range.
*/
double	ft_map_d(t_map_d args)
{
	double	mapped;

	mapped = (args.mapped - args.start1)
		* (args.stop2 - args.start2)
		/ (args.stop1 - args.start1)
		+ args.start2;
	return (mapped);
}
