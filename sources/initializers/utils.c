/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:09:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 02:09:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	command_or_die(t_pipex *ctl, char *raw_cmd)
{
	char	*str;

	str = raw_cmd;
	str = ft_skip_whitespace(str);
	if (ft_strlen(str) == 0)
		die_cmd(ctl, raw_cmd);
}
