# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:02:23 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/03/24 03:46:34 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make --silent re || exit

#./pipex infile "ls" "wc" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "cat" "wc" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "cat -E" "wc -l" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "cat -E" "wc -m" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "ls -l" "wc -l" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "ls -l -a -s" "wc -l" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "ls -l -a -s" "wc -m" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "grep a" "wc -w" outfile; echo $? ; echo $? ; cat outfile
#./pipex .gitignore "tr a b" "tr b c" outfile; echo $? ; echo $? ; cat outfile
#./pipex EOF "tr a b" "tr b c" outfile; echo $? ; echo $? ; cat outfile
#./pipex .gitignore "ping 8.8.8.8" "grep ms" outfile; echo $? ; echo $? ; cat outfile
#./pipex .gitignore "tr x ' '" "tr i ' '" outfile; echo $? ; echo $? ; cat outfile
#./pipex .gitignore "tr ex ' X'" "tr pi 'P '" outfile; echo $? ; echo $? ; cat outfile
./pipex infile "tr a ' '" "tr ' ' x" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "notexisting" "wc" outfile; echo $? ; echo $? ; cat outfile
#./pipex infile "catzado" "wc -w" outfile; echo $? ; echo $? ; cat outfile