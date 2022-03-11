/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:58:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 13:17:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/******************************************************************************\
 * BOOLEANS
\******************************************************************************/

bool				unless(bool condition);

/******************************************************************************\
 * MATH
\******************************************************************************/

int					ft_pow(int number, int power);
int					ft_pow_i(int number, int power);

/******************************************************************************\
 * MEMORY
\******************************************************************************/

# define MALLOC_ERROR_MESSAGE "ERROR: Unable to allocate required memory.\n"

void				*ft_salloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);

/******************************************************************************\
 * CHARS
\******************************************************************************/

bool				ft_is_decimal_char(char character);
bool				ft_is_plus_or_minus(char character);
bool				ft_is_whitespace(char character);
bool				ft_isdigit(int c);

/******************************************************************************\
 * STRINGS
\******************************************************************************/

size_t				ft_strlen(const char *s);
char				*ft_strnchr(const char *s, int c, unsigned int limit);

/******************************************************************************\
 * STRING TO NUMBER
\******************************************************************************/

int					ft_atoi(const char *number_pointer);
unsigned int		ft_atoui(const char *number_pointer);

/******************************************************************************\
 * NUMBER TO STRING
\******************************************************************************/

unsigned int		ft_i_to_buffer(int n, char *buffer);

/******************************************************************************\
 * PRINT STRINGS
\******************************************************************************/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putstr_up_to(char *s, size_t up_to);

/******************************************************************************\
 * PRINT NUMBERS
\******************************************************************************/

# define DEFAULT_PRINT_FLOAT_PRECISION 6

# define DECIMAL_BASE "0123456789"
# define LOWERCASE_HEX_BASE "0123456789abcdef"
# define UPPERCASE_HEX_BASE "0123456789ABCDEF"

bool				ft_is_valid_base(const char *base,
						const size_t base_length);

void				ft_aux_handle_minus_sign_l(long *number_pointer);
void				ft_aux_handle_minus_sign_ll(long long *number_pointer);

void				ft_aux_handle_minus_sign_d(double *number_pointer);
void				ft_aux_handle_minus_sign_ld(long double *number_pointer);

void				ft_putnbr_ui(unsigned int number);
void				ft_putnbr_l(long number);
void				ft_putnbr_ll(long long number);

void				ft_putnbr_base_ui(unsigned int number, const char *base);
void				ft_putnbr_base_l(long number, const char *base);
void				ft_putnbr_base_ul(unsigned long number, const char *base);
void				ft_putnbr_base_ll(long long number, const char *base);

void				ft_putnbr_precise_d(double n, int precision);
void				ft_putnbr_precise_ld(long double n, int precision);

void				ft_puthex_uppercase(unsigned int number);
void				ft_puthex_lowercase(unsigned int number);

unsigned int		ft_count_digits(int number);
unsigned int		ft_count_digits_i(int number);
unsigned int		ft_count_digits_ui(unsigned int number);
unsigned int		ft_count_digits_ull(unsigned long long number);

unsigned int		ft_count_digits_hex_ul(unsigned long number);

unsigned int		ft_count_chars_i(int number);

unsigned int		ft_count_chars_d(double number, int precision);
unsigned int		ft_count_digits_d(double number, int precision);

unsigned int		ft_count_chars_ld(long double number, int precision);
unsigned int		ft_count_digits_ld(long double number, int precision);

char				*ft_skip_number(char *digits);
char				*ft_skip_whitespace(char *digits);

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

int					ft_printf(const char *format, ...);
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
