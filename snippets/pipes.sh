# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pipes.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 18:34:17 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/02/28 09:25:51 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

< infile ls | wc > outfile

< infile ls -l | wc -l > outfile
< infile grep a1 | wc -w > outfile

< .gitignore tr a b | tr b c > outfile
< EOF tr a b | tr b c > outfile
< .gitignore ping 8.8.8.8 | grep ms > outfile
