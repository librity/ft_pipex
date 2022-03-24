/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 15:07:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# define HDOC_IDENTIFIER "here_doc"

/******************************************************************************\
 * MESSAGES
\******************************************************************************/

# define HELP_MSG_NEX "Welcome to lpaulo-m's pipex!\n\
\n\
USAGE:\n\
	./pipex file1 \"cmd1\" \"cmd2\" \"cmd3\" ... \"cmdn\" file2\n\
	behaves like: < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2\n\
\n\
EXAMPLES:\n\
	./pipex infile \"ls -l\" \"grep a\" \"wc -l\" outfile\n\
	./pipex infile \"cat\" \"tr a b\" \"tr b a\" \"tr a b\" \"tr b a\" outfile\n\
\n\
"

# define HELP_MSG_HDOC "Welcome to lpaulo-m's pipex!\n\
\n\
USAGE:\n\
	./pipex here_doc LIMITER \"cmd1\" \"cmd2\" file\n\
	behaves like: cmd1 << LIMITER | cmd2 >> file\n\
\n\
EXAMPLES:\n\
	./pipex here_doc l \"grep a\" \"wc -l\" outfile\n\
	./pipex here_doc x \"cat\" \"tr a b\" outfile\n\
\n\
"

#endif
