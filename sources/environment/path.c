/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 18:23:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	*get_clean_path(char **envp)
{
	char	*candidate;

	while (*envp)
	{
		candidate = ft_strnstr(*envp, PATH_PREFIX, PATH_PREFIX_LENGTH);
		if (candidate != NULL)
			return (candidate + PATH_PREFIX_LENGTH);
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
