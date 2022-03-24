/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 19:12:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static char	*get_clean_path(char **envp)
{
	while (*envp)
	{
		if (ft_starts_with(*envp, PATH_PREFIX))
			return (*envp + PATH_PREFIX_LENGTH);
		envp++;
	}
	return (NULL);
}

char	*get_clean_path_or_die(char **envp)
{
	char	*clean_path;

	clean_path = get_clean_path(envp);
	die_if_null(clean_path);
	return (clean_path);
}
