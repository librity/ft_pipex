/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 20:05:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static bool	starts_with_path(char *env_var)
{
	char	*path_suffix;

	path_suffix = PATH_PREFIX;
	while (*env_var != '\0' && *path_suffix != '\0')
	{
		if (*env_var != *path_suffix)
			return (false);
		env_var++;
		path_suffix++;
	}
	if (*path_suffix != '\0')
		return (false);
	return (true);
}

static char	*get_clean_path(char **envp)
{
	size_t	suffix_lenght;

	suffix_lenght = ft_strlen(PATH_PREFIX);
	while (*envp)
	{
		if (starts_with_path(*envp))
			return ((*envp) + suffix_lenght);
		envp++;
	}
	return (NULL);
}

char	*get_clean_path_or_die(char **envp)
{
	char	*clean_path;

	clean_path = get_clean_path(envp);
	if (clean_path == NULL)
		die();
	return (clean_path);
}
