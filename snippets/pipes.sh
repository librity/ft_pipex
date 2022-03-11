#!/usr/bin/env bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pipes.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 18:34:17 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/03/06 00:01:52 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

< infile ls | wc > outfile; echo $?; cat outfile

< infile ls -l | wc -l > outfile; echo $?; cat outfile
< infile grep a1 | wc -w > outfile; echo $?; cat outfile

< .gitignore tr a b | tr b c > outfile; echo $?; cat outfile
< EOF tr a b | tr b c > outfile; echo $?; cat outfile
< .gitignore ping 8.8.8.8 | grep ms > outfile; echo $?; cat outfile

echo "DIFFERENT EXIT CODES"
< bad cat | grep x > outfile; echo $?
< bad grep x | cat > outfile; echo $?
