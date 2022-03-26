/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clamped_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:16:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Maps an int that varies between a range into a target range.
** If the result lies outside the target
** it returns the closest limit, min or max.
*/
int	ft_map_clamped_i(t_map_i args)
{
	int	mapped;

	mapped = ft_map_i(args);
	if (args.start2 < args.stop2)
		return (ft_clamp_i(mapped, args.start2, args.stop2));
	return (ft_clamp_i(mapped, args.stop2, args.start2));
}
