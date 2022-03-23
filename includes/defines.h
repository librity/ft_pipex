/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 11:42:39 by lpaulo-m         ###   ########.fr       */
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

/******************************************************************************\
 * COLORS
\******************************************************************************/

/* Black, Red, Green, Yellow, Blue, Purple, Cyan, White */
# define BK "\033[0;30m"
# define R "\033[0;31m"
# define G "\033[0;32m"
# define Y "\033[0;33m"
# define B "\033[0;34m"
# define P "\033[0;35m"
# define C "\033[0;36m"
# define W "\033[0;37m"

/* Bold */
# define BKB "\033[1;30m"
# define RB "\033[1;31m"
# define GB "\033[1;32m"
# define YB "\033[1;33m"
# define BB "\033[1;34m"
# define PB "\033[1;35m"
# define CB "\033[1;36m"
# define WB "\033[1;37m"

/* Reset Color */
# define RC "\033[0m"

#endif
