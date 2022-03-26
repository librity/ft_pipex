/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:58:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 01:17:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include <libft.h>

/******************************************************************************\
 * MEMORY
\******************************************************************************/

# define MALLOC_ERROR_MESSAGE "ERROR: Unable to allocate required memory.\n"

/******************************************************************************\
 * PRINT NUMBERS
\******************************************************************************/

# define DEFAULT_PRINT_FLOAT_PRECISION 6

# define DECIMAL_BASE "0123456789"
# define LOWERCASE_HEX_BASE "0123456789abcdef"
# define UPPERCASE_HEX_BASE "0123456789ABCDEF"

/******************************************************************************\
 * FT_GET_NEXT_LINE
\******************************************************************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define MAX_FILE_DESCRIPTOR RLIMIT_NOFILE

/******************************************************************************\
 * FT_PRINTF
\******************************************************************************/

# ifndef ARG_MAX
#  define ARG_MAX 131072
# endif

# define NULL_STRING "(null)"

typedef struct s_printf
{
	const char		*format;
	va_list			elements;
	int				chars_printed;
	unsigned int	conversion_position;
	char			conversion;
}					t_printf;

typedef struct s_parse_flags
{
	char			parsed_flags[ARG_MAX];
	char			*flags;
	bool			has_wildcards;
	bool			is_left_padded_with_zeros;
	bool			is_left_justified;
	char			left_padder;
	bool			has_minimum_width;
	int				minimum_width;
	bool			has_precision;
	int				precision;
}					t_parse_flags;

typedef struct s_parse_wildcards
{
	char			*found_wildcards;
	unsigned int	conversion_position;
	int				wildcard;
	size_t			parser;
}					t_parse_wildcards;

void				pf_vprintf(t_printf *print_control);

void				pf_initialize_print_control(t_printf *print_control,
						const char *format);
void				pf_initialize_flag_control(t_printf *print_control,
						t_parse_flags *flag_control);
void				pf_initialize_wildcard_control(t_printf *print_control,
						t_parse_flags *flag_control,
						t_parse_wildcards *wildcard_control);

void				pf_parse_flags(t_printf *print_control,
						t_parse_flags *control);
void				pf_parse_wildcars(t_printf *print_control,
						t_parse_flags *flag_control);

bool				pf_handled_no_conversion(t_printf *print_control);

/******************************************************************************\
 * FT_PRINTF PERCENT
\******************************************************************************/

typedef struct s_handle_percent
{
	unsigned char	print_me;
	int				char_count;
	t_parse_flags	flag_control;
}					t_handle_percent;
bool				pf_handled_percent(t_printf *print_control);
void				pf_print_percent(t_printf *print_control,
						t_handle_percent *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF CHAR
\******************************************************************************/

typedef struct s_handle_c
{
	unsigned char	print_me;
	int				char_count;
	t_parse_flags	flag_control;
}					t_handle_c;
bool				pf_handled_s(t_printf *print_control);
void				pf_print_c(t_printf *print_control,
						t_handle_c *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF STRING
\******************************************************************************/

typedef struct s_handle_s
{
	char			*print_me;
	size_t			length;
	size_t			precision_length;
	bool			is_null;
	t_parse_flags	flag_control;
}					t_handle_s;
bool				pf_handled_c(t_printf *print_control);
void				pf_print_s(t_printf *print_control,
						t_handle_s *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF INT
\******************************************************************************/

typedef struct s_handle_int
{
	long			print_me;
	int				digit_count;
	int				char_count;
	bool			is_negative;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_int;
bool				pf_handled_int(t_printf *print_control);
void				pf_print_int(t_printf *print_control,
						t_handle_int *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF UNSIGNED INT
\******************************************************************************/

typedef struct s_handle_u
{
	unsigned int	print_me;
	int				digit_count;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_u;
bool				pf_handled_u(t_printf *print_control);
void				pf_print_u(t_printf *print_control,
						t_handle_u *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF POINTERS
\******************************************************************************/

typedef struct s_handle_p
{
	unsigned long	print_me;
	int				digit_count;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_p;
bool				pf_handled_p(t_printf *print_control);
void				pf_printf_p(t_printf *print_control,
						t_handle_p *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF HEXADECIMAL
\******************************************************************************/

typedef struct s_handle_hex
{
	unsigned int	print_me;
	int				digit_count;
	bool			is_uppercase;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_hex;
bool				pf_handled_hex(t_printf *print_control);
void				pf_printf_hex(t_printf *print_control,
						t_handle_hex *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF FLOAT DOUBLE
\******************************************************************************/

typedef struct s_handle_f
{
	double			print_me;
	int				digit_count;
	int				char_count;
	bool			is_negative;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_f;
bool				pf_handled_f(t_printf *print_control);
void				pf_print_f(t_printf *print_control,
						t_handle_f *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF LONG DOUBLE
\******************************************************************************/

typedef struct s_handle_lf
{
	long double		print_me;
	int				digit_count;
	int				char_count;
	bool			is_negative;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_lf;
bool				pf_handled_lf(t_printf *print_control);
void				pf_print_lf(t_printf *print_control,
						t_handle_lf *control,
						t_parse_flags *flag_control);

#endif
