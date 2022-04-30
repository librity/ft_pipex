# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/03/26 18:30:06 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CC_STRICT = $(CC) $(CCF_STRICT) $(CCF_OPTIMIZATION)

CCF_STRICT = -Wall -Wextra -Werror
CCF_INCLUDES = -I $(LIBFT_INCLUDES) -I $(INCLUDES_PATH)
# CCF_OPTIMIZATION = -O3
# CCF_DEBUG = -g -fsanitize=leak

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
ARCHIVES_PATH = ./archives

LIBS_PATH = ./libs

LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INCLUDES = $(LIBFT_PATH)/includes

################################################################################
# MANDATORY
################################################################################

M_HEADER = $(INCLUDES_PATH)/pipex.h
M_ARCHIVE = $(ARCHIVES_PATH)/pipex.a

M_SOURCES_PATH = $(SOURCES_PATH)/mandatory
M_OBJECTS_PATH = $(OBJECTS_PATH)/mandatory

# M_SOURCES = $(wildcard $(M_SOURCES_PATH)/**/*.c) $(wildcard $(M_SOURCES_PATH)/*.c)
M_SOURCES = ./sources/mandatory/children/forks.c ./sources/mandatory/children/left.c ./sources/mandatory/children/right.c ./sources/mandatory/cleanup/memory.c ./sources/mandatory/commands/execute.c ./sources/mandatory/commands/find.c ./sources/mandatory/commands/find_left.c ./sources/mandatory/commands/find_right.c ./sources/mandatory/commands/loggers.c ./sources/mandatory/commands/split.c ./sources/mandatory/commands/tokenize.c ./sources/mandatory/environment/loggers.c ./sources/mandatory/environment/path.c ./sources/mandatory/environment/paths.c ./sources/mandatory/errors/arguments.c ./sources/mandatory/errors/die_1.c ./sources/mandatory/errors/die_2.c ./sources/mandatory/errors/print_error.c ./sources/mandatory/files/close.c ./sources/mandatory/files/create.c ./sources/mandatory/files/create_outfile.c ./sources/mandatory/files/open.c ./sources/mandatory/files/open_infile.c ./sources/mandatory/initializers/children.c ./sources/mandatory/initializers/environment.c ./sources/mandatory/initializers/files.c ./sources/mandatory/initializers/fourex.c ./sources/mandatory/initializers/left.c ./sources/mandatory/initializers/right.c ./sources/mandatory/initializers/utils.c ./sources/mandatory/pipes/core.c ./sources/mandatory/pipes/redirections.c ./sources/mandatory/fourex.c

M_OBJECTS = $(patsubst $(M_SOURCES_PATH)/%.c, $(M_OBJECTS_PATH)/%.o, $(M_SOURCES))
M_OBJECT_DIRECTORIES = $(sort $(dir $(M_OBJECTS)))

M_MAIN = ./main.c

M_ARCHIVES = $(M_ARCHIVE) $(LIBFT)

all: $(NAME)

$(NAME): $(LIBFT) $(M_ARCHIVE)
	$(CC_STRICT) $(CCF_DEBUG) \
		$(CCF_INCLUDES) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		-o $(NAME)

$(M_ARCHIVE): $(M_HEADER) $(M_OBJECTS)
	$(ARCHIVE_AND_INDEX) $(M_ARCHIVE) $(M_OBJECTS)

$(M_OBJECTS_PATH)/%.o: $(M_SOURCES_PATH)/%.c
	$(CC_STRICT) $(CCF_INCLUDES) -c -o $@ $<

clean:
	$(REMOVE) $(M_OBJECTS)
	$(REMOVE) $(M_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

################################################################################
# BONUS
################################################################################

B_HEADER = $(INCLUDES_PATH)/pipex_bonus.h
B_ARCHIVE = $(ARCHIVES_PATH)/pipex_bonus.a

B_SOURCES_PATH = $(SOURCES_PATH)/bonus
B_OBJECTS_PATH = $(OBJECTS_PATH)/bonus

# B_SOURCES = $(wildcard $(B_SOURCES_PATH)/**/*.c) $(wildcard $(B_SOURCES_PATH)/*.c)
B_SOURCES = ./sources/bonus/children/child.c ./sources/bonus/children/forks.c ./sources/bonus/children/hdoc.c ./sources/bonus/cleanup/memory.c ./sources/bonus/commands/execute.c ./sources/bonus/commands/find.c ./sources/bonus/commands/or_die.c ./sources/bonus/commands/path.c ./sources/bonus/commands/paths.c ./sources/bonus/commands/split.c ./sources/bonus/commands/tokenize.c ./sources/bonus/errors/arguments.c ./sources/bonus/errors/die_1.c ./sources/bonus/errors/die_2.c ./sources/bonus/errors/print_error.c ./sources/bonus/files/close.c ./sources/bonus/files/create.c ./sources/bonus/files/create_outfile.c ./sources/bonus/files/open.c ./sources/bonus/files/open_infile.c ./sources/bonus/initializers/control.c ./sources/bonus/initializers/hdoc.c ./sources/bonus/initializers/nex.c ./sources/bonus/pipes/core.c ./sources/bonus/pipes/file.c ./sources/bonus/pipes/stdin.c ./sources/bonus/pipes/stdout.c ./sources/bonus/pipes/write.c ./sources/bonus/nex.c

B_OBJECTS = $(patsubst $(B_SOURCES_PATH)/%.c, $(B_OBJECTS_PATH)/%.o, $(B_SOURCES))
B_OBJECT_DIRECTORIES = $(sort $(dir $(B_OBJECTS)))

B_MAIN = ./main_bonus.c

B_ARCHIVES = $(B_ARCHIVE) $(LIBFT)

allb: bonus

bonus: $(LIBFT) $(B_ARCHIVE)
	$(CC_STRICT) $(CCF_DEBUG) \
		$(CCF_INCLUDES) \
		$(B_MAIN) \
		$(B_ARCHIVES) \
		-o $(NAME)

$(B_ARCHIVE): $(B_HEADER) $(B_OBJECTS)
	$(ARCHIVE_AND_INDEX) $(B_ARCHIVE) $(B_OBJECTS)

$(B_OBJECTS_PATH)/%.o: $(B_SOURCES_PATH)/%.c
	$(CC_STRICT) $(CCF_INCLUDES) -c -o $@ $<


cleanb:
	$(REMOVE) $(B_OBJECTS)
	$(REMOVE) $(B_ARCHIVE)

fcleanb: cleanb
	$(REMOVE) $(NAME)

reb: fcleanb bonus

################################################################################
# DIRS
################################################################################

make_dirs: $(ARCHIVES_PATH) $(OBJECTS_PATH) \
	$(M_OBJECT_DIRECTORIES) $(B_OBJECT_DIRECTORIES)

$(ARCHIVES_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

$(M_OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

$(B_OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

################################################################################
# CLEAN
################################################################################

tclean: clean_libs fclean fcleanb tests_clean example_clean vglog_clean

################################################################################
# LIBS
################################################################################

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH) all

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean_libs: libft_clean

################################################################################
# TESTS
################################################################################

TESTS_PATH = ./tests

TEST_SOURCES = $(wildcard $(TESTS_PATH)/*.c)
CCF_TEST_LIBS = -lrt -lm
EXECUTE_TESTS = ./test

build_tests: re
	$(CC) $(CCF_DEBUG) \
		$(CCF_INCLUDES) \
		$(TEST_SOURCES) \
		$(M_ARCHIVES) \
		$(CCF_TEST_LIBS) \
		-o $(EXECUTE_TESTS)

test: build_tests
	$(EXECUTE_TESTS)

tests_clean:
	$(REMOVE_RECURSIVE) $(EXECUTE_TESTS)

################################################################################
# EXAMPLE
################################################################################

EXAMPLES_PATH = ./examples

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: build_example
	$(EXECUTE_EXAMPLE)

build_example: $(M_ARCHIVE)
	$(CC) $(CCF_DEBUG) \
		$(CCF_INCLUDES) \
		$(EXAMPLE_MAIN) \
		$(M_ARCHIVES)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --trace-children=yes
VALGRIND_LOG = valgrind_leaks.log
VALGRIND_LOG_FLAGS = --log-file=$(VALGRIND_LOG) \
	--leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \
	--track-origins=yes \
	--verbose
VALGRIND_TARGET = ./$(NAME) infile "grep pipex" "wc -lw" outfile && cat outfile

vg: vg_build
	$(VALGRIND) $(VALGRIND_FLAGS) $(VALGRIND_TARGET)

vglog: vg_build
	$(VALGRIND) $(VALGRIND_LOG_FLAGS) $(VALGRIND_TARGET)

vg_build: $(M_ARCHIVE)
	$(CC_STRICT) \
		$(CCF_INCLUDES) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VALGRIND_LOG)

################################################################################
# MISC
################################################################################

norm:
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"
	norminette $(M_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(M_MAIN) ===$(RC)\n\n"
	norminette $(B_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(B_MAIN) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "AUTOMATIC MESSAGE"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

dump_sources:
	@echo =========== MANDATORY ===========
	@echo "M_SOURCES = $(M_SOURCES)"
	@echo ============= BONUS =============
	@echo "B_SOURCES = $(B_SOURCES)"
	@echo =================================

################################################################################
# PHONY
################################################################################

.PHONY: \
all clean fclean re \
\
allb bonus cleanb fcleanb reb \
\
make_dirs \
\
tclean \
\
libft_clean clean_libs \
\
build_tests test tests_clean \
\
example build_example example_clean \
\
vg vglog vg_build vglog_clean \
\
norm git gitm dump_sources

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m
