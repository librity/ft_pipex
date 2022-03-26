/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 20:26:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**split_command_or_die(char *raw_command)
{
	char	**split_command;

	split_command = ft_split(raw_command, ' ');
	die_if_null(split_command);
	return (split_command);
}
