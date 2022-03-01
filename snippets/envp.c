/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/28 13:34:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc envp.c && ./a.out

#include <stdbool.h>
#include <stdio.h>

#define PATH "PATH="

static bool	starts_with_PATH(char *full_path)
{
	char	*path_suffix;

	path_suffix = PATH;
	while (*full_path != NULL && *path_suffix != NULL)
	{
		if (*full_path != *path_suffix)
			return (false);
		full_path++;
		path_suffix++;
	}
	if (*path_suffix != NULL)
		return (false);
	return (true);
}

static char	*skip_PATH(char *full_path)
{
	char	*path_suffix;
	char	*clean_path;

	path_suffix = PATH;
	clean_path = full_path;
	while (*clean_path != NULL && *path_suffix != NULL)
	{
		if (*clean_path != *path_suffix)
			return (NULL);
		clean_path++;
		path_suffix++;
	}
	return (clean_path);
}

static char	*get_full_path(char **envp)
{
	while (*envp)
	{
		if (starts_with_PATH(*envp))
			return (*envp);
		envp++;
	}
	return (NULL);
}

static void	print_environment_variables(char **environment_variables)
{
	int	ev_count;

	ev_count = 0;
	printf("=== ENVIRONMENT VARIABLES ===\n");
	while (*environment_variables)
	{
		printf("%s\n", *environment_variables++);
		ev_count++;
	}
	printf("COUNT: %i\n", ev_count);
}

int	main(int argc, char **argv, char **envp)
{
	char	*paths;

	print_environment_variables(envp);
	paths = get_full_path(envp);
	paths = skip_PATH(paths);
	printf("=== PATHS ===\n");
	printf("%s\n", paths);
}
