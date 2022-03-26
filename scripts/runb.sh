# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    runb.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:02:23 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/03/25 23:10:59 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make reb || exit

# ./pipex
./pipex inile "grep a" "grep d" "grep s" outfile
# ./pipex here_doc 33 "grep a" "grep d" outfile \
# a\
# a\
# aa\
# a\
# d\
# f\
# t\
# e\
# sf\
# \
# a\
# \
# ads\
# 33a\
# 333\
# 33
