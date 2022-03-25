/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 13:25:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize_pipes(t_pipex *ctl)
{
	pipe_or_die(ctl->left.in_pipe);
	pipe_or_die(ctl->right.in_pipe);
	ctl->left.out_pipe = ctl->right.in_pipe;
}

void	initialize_hdoc(t_pipex *ctl, int argc, char **argv, char **envp)
{
	ctl->argc = argc;
	ctl->argv = argv;
	ctl->envp = envp;
	ctl->free_me = NULL;
	initialize_pipes(ctl);
	initialize_environment(ctl);
}

void	initialize_hdoc_left(t_pipex *ctl)
{
	ctl->left.limiter = ctl->argv[2];
	ctl->left.raw = ctl->argv[3];
	command_or_die(ctl, ctl->left.raw);
	ctl->left.tokens = tokenize_or_die(ctl->left.raw);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->left.tokens);
	ctl->left.cmd = ctl->left.tokens[0];
	set_child_executable_or_die(ctl, &(ctl->left));
	ctl->left.flags = ctl->left.tokens + 1;
	log_command(ctl->left.path, ctl->left.flags);
}

void	initialize_hdoc_right(t_pipex *ctl)
{
	ctl->right.raw = ctl->argv[4];
	command_or_die(ctl, ctl->right.raw);
	ctl->right.tokens = tokenize_or_die(ctl->right.raw);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->right.tokens);
	ctl->right.cmd = ctl->right.tokens[0];
	set_child_executable_or_die(ctl, &(ctl->right));
	ctl->right.flags = ctl->right.tokens + 1;
	log_command(ctl->right.path, ctl->right.flags);
}
