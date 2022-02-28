/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/28 13:16:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc envp.c && ./a.out

#include <stdbool.h>
#include <stdio.h>

#define PATH "PATH="

static bool	starts_with_PATH(char *env_var)
{
	char	*path;

	path = PATH;
	while (*env_var != NULL && *path != NULL)
	{
		if (*env_var != *path)
			return (false);
		env_var++;
		path++;
	}
	if (*path != NULL)
		return (false);
	return (true);
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

static char	*get_path(char **envp)
{
	while (*envp)
	{
		if (starts_with_PATH(*envp))
			return (*envp);
		envp++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	print_environment_variables(envp);
	path = get_path(envp);
	printf("=== PATH ===\n");
	printf("%s\n", path);
}
