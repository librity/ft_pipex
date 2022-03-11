/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 00:58:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	log_path(t_pipex *ctl)
{
	if (VERBOSE)
		ft_printf(" => PATH: \"%s\"\n", ctl->path);
}

void	log_paths(t_pipex *ctl)
{
	if (VERBOSE)
	{
		ft_printf(" => PATHS:\n");
		ft_putstr_array(ctl->paths);
		ft_printf("	TOTAL: %d\n", ft_arrlen((void **)ctl->paths));
	}
}

void	log_command(char *command_executable, char **flags)
{
	if (VERBOSE)
	{
		ft_printf(" => EXECUTABLE: %s\n", command_executable);
		ft_printf(" => FLAGS:\n");
		ft_putstr_array(flags);
		ft_printf("	TOTAL: %d\n", ft_arrlen((void **)flags));
	}
}

void	log_pipex(t_pipex *ctl)
{
	if (VERBOSE)
		ft_printf(
			" => Executing \"< %s %s | %s > %s\"\n",
			ctl->infile.path,
			ctl->left.raw,
			ctl->right.raw,
			ctl->outfile.path);
}
