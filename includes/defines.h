/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 17:14:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VERBOSE 1

# define CHILD_PROCESS_ID 0

# define CREATE_PERMISSION 0000664

# define PATH_PREFIX "PATH="
# define PATH_PREFIX_LENGTH 5

# define HELP_MSG "Welcome to lpaulo-m's pipex!\n\
\n\
USAGE:\n\
	./pipex file1 cmd1 cmd2 file2\n\
\n\
EXAMPLES:\n\
	./pipex infile \"ls -l\" \"wc -l\" outfile\n\
	./pipex infile \"grep a1\" \"wc -w\" outfile\n\
\n\
"

#endif
