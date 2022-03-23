/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/23 15:42:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VERBOSE 0

# define CHILD_PROCESS_ID 0

# define PIPE_READ 0
# define PIPE_WRITE 1

# define CREATE_PERMISSION 0000664

# define PATH_PREFIX "PATH="
# define PATH_PREFIX_LENGTH 5

# define NOT_ASCII -42

/******************************************************************************\
 * MESSAGES
\******************************************************************************/

# define HELP_MSG "Welcome to lpaulo-m's pipex!\n\
\n\
USAGE:\n\
	./pipex file1 \"cmd1\" \"cmd2\" file2\n\
\n\
EXAMPLES:\n\
	./pipex infile \"ls -l\" \"wc -l\" outfile\n\
	./pipex infile \"grep a1\" \"wc -w\" outfile\n\
\n\
"

/******************************************************************************\
 * ERRORS
\******************************************************************************/

# define EXIT_SUCCESS_STR "0\n"
# define EXIT_FAILURE_STR "1\n"

# define EKEYEXPIRED 127
# define EKEYEXPIRED_STR "127\n"

# define ERR_GENERIC_RED "\033[0;31mERROR"
# define ERR_NULL_POINTER "ERROR: critical null pointer"
# define ERR_NO_CMD "command not found"

#endif
