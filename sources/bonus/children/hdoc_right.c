/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 22:15:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize(t_pipex *ctl)
{
	initialize_outfile(ctl);
	initialize_hdoc_right(ctl);
}

void	handle_hdoc_right(t_pipex *ctl)
{
	initialize(ctl);
	redirect_right(ctl);
	execute_or_die(ctl->right.path, ctl->right.tokens, ctl->envp);
	free_memory(ctl);
}
