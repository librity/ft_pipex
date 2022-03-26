# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 21:58:14 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/03/26 15:10:45 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
TESTS_PATH = ./tests

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
CC_STRICT = $(CC) $(CC_FLAGS)
CC_DEBUG_FLAGS = -g -fsanitize=address

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

HEADER_FILE = libft.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

# SOURCES = $(wildcard $(SOURCES_PATH)/**/*.c) $(wildcard $(SOURCES_PATH)/*.c)
SOURCES = ./sources/arrays/ft_arrlen.c ./sources/arrays/ft_arrsize.c ./sources/binary/ft_print_bits.c ./sources/binary/ft_print_bits_i.c ./sources/binary/ft_print_bits_ui.c ./sources/binary/ft_print_bits_ul.c ./sources/binary/ft_print_bits_ull.c ./sources/booleans/unless.c ./sources/chars/ft_isalnum.c ./sources/chars/ft_isalpha.c ./sources/chars/ft_isascii.c ./sources/chars/ft_is_decimal_char.c ./sources/chars/ft_isdigit.c ./sources/chars/ft_islower.c ./sources/chars/ft_is_plus_or_minus.c ./sources/chars/ft_isprint.c ./sources/chars/ft_isupper.c ./sources/chars/ft_is_whitespace.c ./sources/chars/ft_tolower.c ./sources/chars/ft_toupper.c ./sources/colors/ft_black.c ./sources/colors/ft_blue.c ./sources/colors/ft_cyan.c ./sources/colors/ft_green.c ./sources/colors/ft_purple.c ./sources/colors/ft_red.c ./sources/colors/ft_white.c ./sources/colors/ft_yellow.c ./sources/get_next_line/ft_get_next_line.c ./sources/get_next_line/ft_gnl.c ./sources/lalloc/ft_add_lalloc_array.c ./sources/lalloc/ft_add_lalloc.c ./sources/lalloc/ft_free_lalloc.c ./sources/lalloc/ft_lalloc.c ./sources/linked_lists/ft_lstadd_back.c ./sources/linked_lists/ft_lst_add.c ./sources/linked_lists/ft_lstadd_front.c ./sources/linked_lists/ft_lst_append.c ./sources/linked_lists/ft_lstclear.c ./sources/linked_lists/ft_lst_create_append.c ./sources/linked_lists/ft_lst_create_prepend.c ./sources/linked_lists/ft_lstdelone.c ./sources/linked_lists/ft_lst_free.c ./sources/linked_lists/ft_lstiter.c ./sources/linked_lists/ft_lstlast.c ./sources/linked_lists/ft_lstmap.c ./sources/linked_lists/ft_lstmap_safe.c ./sources/linked_lists/ft_lstnew.c ./sources/linked_lists/ft_lstnew_safe.c ./sources/linked_lists/ft_lst_prepend.c ./sources/linked_lists/ft_lstsize.c ./sources/math/ft_abs.c ./sources/math/ft_abs_d.c ./sources/math/ft_abs_f.c ./sources/math/ft_abs_i.c ./sources/math/ft_abs_ld.c ./sources/math/ft_clamp_d.c ./sources/math/ft_clamp_i.c ./sources/math/ft_div_mod.c ./sources/math/ft_div_mod_i.c ./sources/math/ft_factorial.c ./sources/math/ft_fibonacci.c ./sources/math/ft_lerp_d.c ./sources/math/ft_lerp_i.c ./sources/math/ft_lerp_wsteps_d.c ./sources/math/ft_lerp_wsteps_i.c ./sources/math/ft_map_clamped_d.c ./sources/math/ft_map_clamped_i.c ./sources/math/ft_map_d.c ./sources/math/ft_map_i.c ./sources/math/ft_max_d.c ./sources/math/ft_max_i.c ./sources/math/ft_min_d.c ./sources/math/ft_min_i.c ./sources/math/ft_pow.c ./sources/math/ft_pow_i.c ./sources/math/ft_pow_ll.c ./sources/math/ft_sqrt.c ./sources/math/ft_sqrt_i.c ./sources/math/ft_swap.c ./sources/math/ft_swap_i.c ./sources/memory/ft_bzero.c ./sources/memory/ft_calloc.c ./sources/memory/ft_memccpy.c ./sources/memory/ft_memchr.c ./sources/memory/ft_memcmp.c ./sources/memory/ft_memcpy.c ./sources/memory/ft_memmove.c ./sources/memory/ft_memset.c ./sources/memory/ft_salloc.c ./sources/number_to_string/ft_dtoa.c ./sources/number_to_string/ft_ftoa.c ./sources/number_to_string/ft_itoa.c ./sources/number_to_string/ft_i_to_buffer.c ./sources/number_to_string/ft_ldtoa.c ./sources/number_to_string/ft_ltoa.c ./sources/number_to_string/ft_precise_dtoa.c ./sources/number_to_string/ft_precise_ftoa.c ./sources/number_to_string/ft_precise_ldtoa.c ./sources/printf/pf_handled_c.c ./sources/printf/pf_handled_f.c ./sources/printf/pf_handled_hex.c ./sources/printf/pf_handled_int.c ./sources/printf/pf_handled_lf.c ./sources/printf/pf_handled_no_conversion.c ./sources/printf/pf_handled_p.c ./sources/printf/pf_handled_percent.c ./sources/printf/pf_handled_s.c ./sources/printf/pf_handled_u.c ./sources/printf/pf_initializers.c ./sources/printf/pf_parse_flags.c ./sources/printf/pf_parse_wildcars.c ./sources/printf/pf_print_c.c ./sources/printf/pf_print_f.c ./sources/printf/pf_printf.c ./sources/printf/pf_print_hex.c ./sources/printf/pf_print_int.c ./sources/printf/pf_print_lf.c ./sources/printf/pf_print_p.c ./sources/printf/pf_print_percent.c ./sources/printf/pf_print_s.c ./sources/printf/pf_print_u.c ./sources/printf/pf_vprintf.c ./sources/print_numbers/ft_aux_handle_minus_sign_d.c ./sources/print_numbers/ft_aux_handle_minus_sign_f.c ./sources/print_numbers/ft_aux_handle_minus_sign_l.c ./sources/print_numbers/ft_aux_handle_minus_sign_ld.c ./sources/print_numbers/ft_aux_handle_minus_sign_ll.c ./sources/print_numbers/ft_count_chars_d.c ./sources/print_numbers/ft_count_chars_f.c ./sources/print_numbers/ft_count_chars_i.c ./sources/print_numbers/ft_count_chars_ld.c ./sources/print_numbers/ft_count_digits.c ./sources/print_numbers/ft_count_digits_d.c ./sources/print_numbers/ft_count_digits_f.c ./sources/print_numbers/ft_count_digits_hex_ui.c ./sources/print_numbers/ft_count_digits_hex_ul.c ./sources/print_numbers/ft_count_digits_i.c ./sources/print_numbers/ft_count_digits_ld.c ./sources/print_numbers/ft_count_digits_ui.c ./sources/print_numbers/ft_count_digits_ul.c ./sources/print_numbers/ft_count_digits_ull.c ./sources/print_numbers/ft_is_valid_base.c ./sources/print_numbers/ft_puthex_lowercase.c ./sources/print_numbers/ft_puthex_uppercase.c ./sources/print_numbers/ft_putnbr_base.c ./sources/print_numbers/ft_putnbr_base_i.c ./sources/print_numbers/ft_putnbr_base_l.c ./sources/print_numbers/ft_putnbr_base_ll.c ./sources/print_numbers/ft_putnbr_base_ui.c ./sources/print_numbers/ft_putnbr_base_ul.c ./sources/print_numbers/ft_putnbr_base_ull.c ./sources/print_numbers/ft_putnbr.c ./sources/print_numbers/ft_putnbr_d.c ./sources/print_numbers/ft_putnbr_f.c ./sources/print_numbers/ft_putnbr_fd.c ./sources/print_numbers/ft_putnbr_i.c ./sources/print_numbers/ft_putnbr_l.c ./sources/print_numbers/ft_putnbr_ld.c ./sources/print_numbers/ft_putnbr_ll.c ./sources/print_numbers/ft_putnbr_precise_d.c ./sources/print_numbers/ft_putnbr_precise_f.c ./sources/print_numbers/ft_putnbr_precise_ld.c ./sources/print_numbers/ft_putnbr_ui.c ./sources/print_numbers/ft_putnbr_ul.c ./sources/print_numbers/ft_putnbr_ull.c ./sources/print_numbers/ft_skip_commas.c ./sources/print_numbers/ft_skip_digits.c ./sources/print_numbers/ft_skip_float.c ./sources/print_numbers/ft_skip_float_commas.c ./sources/print_numbers/ft_skip_float_whitespace.c ./sources/print_numbers/ft_skip_int.c ./sources/print_numbers/ft_skip_int_commas.c ./sources/print_numbers/ft_skip_int_whitespace.c ./sources/print_numbers/ft_skip_number.c ./sources/print_numbers/ft_skip_plus_or_minus.c ./sources/print_numbers/ft_skip_whitespace.c ./sources/print_strings/ft_putchar.c ./sources/print_strings/ft_putchar_fd.c ./sources/print_strings/ft_putendl.c ./sources/print_strings/ft_putendl_fd.c ./sources/print_strings/ft_putstr_array.c ./sources/print_strings/ft_putstr.c ./sources/print_strings/ft_putstr_fd.c ./sources/print_strings/ft_putstr_up_to.c ./sources/strings/ft_free_string_array.c ./sources/strings/ft_split.c ./sources/strings/ft_starts_with.c ./sources/strings/ft_strchr.c ./sources/strings/ft_strcpy.c ./sources/strings/ft_strdel.c ./sources/strings/ft_strdup.c ./sources/strings/ft_streq.c ./sources/strings/ft_strjoin.c ./sources/strings/ft_strjoin_del.c ./sources/strings/ft_strjoin_del_del.c ./sources/strings/ft_strjoin_free.c ./sources/strings/ft_strjoin_free_free.c ./sources/strings/ft_strlcat.c ./sources/strings/ft_strlcpy.c ./sources/strings/ft_strlen.c ./sources/strings/ft_strmapi.c ./sources/strings/ft_strnchr.c ./sources/strings/ft_strncmp.c ./sources/strings/ft_strnstr.c ./sources/strings/ft_strrchr.c ./sources/strings/ft_strsize.c ./sources/strings/ft_strtrim.c ./sources/strings/ft_substr.c ./sources/string_to_number/ft_atof.c ./sources/string_to_number/ft_atoi.c ./sources/string_to_number/ft_atol.c ./sources/string_to_number/ft_atold.c ./sources/string_to_number/ft_atoll.c ./sources/string_to_number/ft_atoui.c ./sources/string_to_number/ft_atoui_strict.c ./sources/string_to_number/ft_atoul.c ./sources/string_to_number/ft_atoull.c

OBJECTS = $(patsubst $(SOURCES_PATH)/%.c, $(OBJECTS_PATH)/%.o, $(SOURCES))
OBJECT_DIRECTORIES = $(sort $(dir $(OBJECTS)))

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

$(NAME): $(HEADER) $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(CC_STRICT) -I $(INCLUDES_PATH) -c -o $@ $<

re: fclean all

################################################################################
# INITIALIZE
################################################################################

initialize: make_dirs

make_dirs: $(OBJECTS_PATH) $(OBJECT_DIRECTORIES)

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

$(OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

################################################################################
# CLEAN
################################################################################

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

################################################################################
# TESTS
################################################################################

test:
	$(MAKE_EXTERNAL) $(TESTS_PATH)

test_clean:
	$(MAKE_EXTERNAL) $(TESTS_PATH) fclean

################################################################################
# EXAMPLE
################################################################################

EXAMPLE_MAIN = examples/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: build_example
	$(EXECUTE_EXAMPLE)

build_example: $(NAME)
	$(CC) $(CC_DEBUG_FLAGS) -I $(INCLUDES_PATH) $(EXAMPLE_MAIN) $(NAME)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

VALGRIND = valgrind
VALGRIND_TARGET = ./a.out

vg: build_example
	$(VALGRIND) $(VALGRIND_TARGET)

################################################################################
# MISC
################################################################################

norm:
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "update"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

dump_sources:
	@echo =========== SOURCES ===========
	@echo "SOURCES = $(SOURCES)"
	@echo ===============================

################################################################################
# PHONY
################################################################################

.PHONY: all re \
	initialize make_dirs \
	clean fclean \
\
	test_clean test \
	example build_example example_clean \
	vg \
\
	norm git gitm dump_sources

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
Bk = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BkB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC	= \033[0m
