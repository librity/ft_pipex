/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 19:59:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	initialize(t_initialize args)
{
	initialize_pipex(args.ctl, args.left, args.right);
	initialize_environment(args.ctl, args.envp);
	initialize_arguments(args.ctl, args.argc, args.argv);
}
