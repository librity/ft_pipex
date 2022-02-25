# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/02/25 10:42:15 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftctemplate

FTCTEMPLATE_HEADER = $(INCLUDES_PATH)/ftctemplate.h
FTCTEMPLATE_ARCHIVE = $(ARCHIVES_PATH)/ftctemplate.a

CC = gcc
CC_STRICT = $(CC) $(CCF_STRICT) $(CCF_OPTIMIZATION)

CCF_STRICT = -Wall -Wextra -Werror
CCF_OPTIMIZATION = -O3
CCF_DEBUG = -g -fsanitize=leak

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

SOURCES = $(wildcard $(SOURCES_PATH)/**/*.c) $(wildcard $(SOURCES_PATH)/*.c)

OBJECTS = $(patsubst $(SOURCES_PATH)/%.c, $(OBJECTS_PATH)/%.o, $(SOURCES))
OBJECT_DIRECTORIES = $(sort $(dir $(OBJECTS)))

ARCHIVES = $(FTCTEMPLATE_ARCHIVE)

################################################################################
# REQUIRED
################################################################################

REQUIRED_MAIN = ./main.c

all: $(NAME)

$(NAME): $(FTCTEMPLATE_ARCHIVE)
	$(CC_STRICT) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(REQUIRED_MAIN) \
		$(ARCHIVES) \
		$(CCF_LIBS) \
		-o $(NAME)

$(FTCTEMPLATE_ARCHIVE): initialize $(FTCTEMPLATE_HEADER) $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(FTCTEMPLATE_ARCHIVE) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(CC_STRICT) -I $(INCLUDES_PATH) -c -o $@ $<

re: fclean all

################################################################################
# INITIALIZE
################################################################################

initialize: make_dirs

make_dirs: $(ARCHIVES_PATH) $(OBJECTS_PATH) $(OBJECT_DIRECTORIES)

$(ARCHIVES_PATH):
	$(SAFE_MAKEDIR) $@

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@

$(OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@

################################################################################
# CLEAN
################################################################################

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(FTCTEMPLATE_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

tclean: fclean tests_clean example_clean vglog_clean

################################################################################
# TESTS
################################################################################

TESTS_PATH = ./tests

TEST_SOURCES = $(wildcard $(TESTS_PATH)/*.c)
CCF_TEST_LIBS = -lrt -lm
EXECUTE_TESTS = ./test

build_tests: re
	$(CC) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(TEST_SOURCES) \
		$(ARCHIVES) \
		$(CCF_LIBS) $(CCF_TEST_LIBS) \
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

build_example: $(FTCTEMPLATE_ARCHIVE)
	$(CC) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(EXAMPLE_MAIN) $(FTCTEMPLATE_ARCHIVE) \
		$(CCF_LIBS)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all
VALGRIND_LOG = valgrind_leaks.log
VALGRIND_LOG_FLAGS = --log-file=$(VALGRIND_LOG) \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose
VALGRIND_TARGET = ./$(NAME) julia   -0.391    -0.587

vg: vg_build
	$(VALGRIND) $(VALGRIND_FLAGS) $(VALGRIND_TARGET)

vglog: vg_build
	$(VALGRIND) $(VALGRIND_LOG_FLAGS) $(VALGRIND_TARGET)

vg_build: $(FTCTEMPLATE_ARCHIVE)
	$(CC_STRICT) \
		-I $(INCLUDES_PATH) \
		$(REQUIRED_MAIN) \
		$(ARCHIVES) \
		$(CCF_LIBS) \
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
	norminette $(REQUIRED_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(REQUIRED_MAIN) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "AUTOMATIC MESSAGE"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

################################################################################
# PHONY
################################################################################

.PHONY: all required clean fclean re \
	initialize make_dirs \
\
	build_tests test tests_clean \
	build_example example example_clean \
	vg vglog vg_build vglog_clean \
\
	tclean \
	norm git gitm

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
