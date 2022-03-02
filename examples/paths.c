/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:55:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 23:50:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	print_paths(char **paths)
{
	int paths_count;

	paths_count = 0;
	ft_printf(" => PATHS:\n");
	while(*paths)
	{
		ft_printf("	\"%s\"\n", *paths++);
		paths_count++;
	}
	ft_printf("	TOTAL: %d\n", paths_count);
}

void	free_string_array(char **free_me)
{
	char	**free_me_too;

	free_me_too = free_me;
	while(*free_me)
		free(*free_me++);
	free(free_me_too);
}

int	main(int argc, char **argv, char **envp)
{
	char *clean_path;
	char **paths;
	char *ls_args[] = {"-l", "-a",  NULL};

	clean_path = get_clean_path_or_die(envp);
	ft_printf(" => PATH: \"%s\"\n", clean_path);

	paths = ft_split(clean_path, ':');
	print_paths(paths);
	free_string_array(paths);

	return (EXIT_SUCCESS);
}
