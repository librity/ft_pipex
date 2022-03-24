# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    demo.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:00:58 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/03/24 00:47:38 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK="\033[0;30m"
R="\033[0;31m"
G="\033[0;32m"
Y="\033[0;33m"
B="\033[0;34m"
P="\033[0;35m"
C="\033[0;36m"
W="\033[0;37m"
# Bold
BKB="\033[1;30m"
RB="\033[1;31m"
GB="\033[1;32m"
YB="\033[1;33m"
BB="\033[1;34m"
PB="\033[1;35m"
CB="\033[1;36m"
WB="\033[1;37m"
# Reset Color
RC="\033[0m"

print_exit_code() {
	printf "${C}Exit Code: "
	echo $1
	printf "${RC}"
}

print_outfile() {
	printf "${Y}Outfile:"
	echo
	echo "\"\"\""
	cat $1
	printf "\"\"\"${RC}"
	echo
}

run_pipex() {
	rm $4
	printf "${P}========================= PIPEX =======================${RC}\n"
	printf "${G}Command: ./pipex $1 \"$2\" \"$3\" $4${RC}"
	echo

	printf "${B}Output:"
	echo
	./pipex "$1" "$2" "$3" "$4"
	exit_code=$?
	printf "${RC}"
	echo

	print_exit_code "$exit_code"
	print_outfile "$4"
}

run_shell() {
	rm $4
	printf "${P}========================= SHELL =======================${RC}\n"
	printf "${G}Command: < $1 $2 | $3 > $4${RC}"
	echo

	printf "${B}Output:"
	echo
	eval "< $1 $2 | $3 > $4"
	exit_code=$?
	printf "${RC}"
	echo

	print_exit_code "$exit_code"
	print_outfile "$4"
}

print_terminator() {
	printf "${P}=======================================================${RC}\n"
	echo
	echo
}

compare() {
	run_pipex "$1" "$2" "$3" "$4"
	run_shell "$1" "$2" "$3" "$4"

	print_terminator
}

make --silent re || exit

# compare infile "grep a" "wc -w" outfile

# compare infile "ls" "wc" outfile
# compare infile "ls -la" "grep *.c" outfile
# compare infile "ls -la" "bad *.c" outfile
# compare infile "ls -l" "wc -l" outfile
# compare infile "ls -l -a -s" "wc -l" outfile
# compare infile "ls -l -a -s" "wc -m" outfile

# compare infile "cat" "wc" outfile
# compare infile "cat -E" "wc -l" outfile
# compare infile "cat -E" "wc -m" outfile

# compare .gitignore "tr a b" "tr b c" outfile
# compare EOF "tr a b" "tr b c" outfile
# compare .gitignore "tr x ' '" "tr i ' '" outfile

# compare .gitignore "tr ex ' X'" "tr pi 'P '" outfile
# compare "infile" "tr a ' '" "tr ' ' x" "outfile"

compare infile "grep pipex" "wc -lw" outfile
# compare infile "cat" "trzero a b" outfile
# compare infile "notexisting" "wc" outfile
# compare infile "catzado" "wc -w" outfile

# compare bad "cat" "grep x" outfile
# compare bad "grep x" "cat" outfile

# compare .gitignore "ping 8.8.8.8" "grep ms" outfile
