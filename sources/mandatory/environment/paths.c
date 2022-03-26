/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 18:23:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**get_paths_or_die(char **envp)
{
	char	*clean_path;
	char	**paths;

	clean_path = get_clean_path_or_die(envp);
	paths = ft_split(clean_path, ':');
	die_if_null(paths);
	return (paths);
}
