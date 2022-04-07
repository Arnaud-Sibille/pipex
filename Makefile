# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asibille <asibille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 09:29:58 by asibille          #+#    #+#              #
#    Updated: 2022/04/07 09:30:04 by asibille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Mand_part/utils/ft_split.c Mand_part/utils/ft_strjoin.c Mand_part/utils/ft_strlen.c Mand_part/utils/ft_substr.c\
		Mand_part/cmd_to_path.c Mand_part/exec.c Mand_part/exit.c

MAIN = Mand_part/pipex.c 

OBJS = ${SRCS:.c=.o}

MAINOBJ = ${MAIN:.c=.o}

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS} ${MAINOBJ}
	gcc ${CFLAGS} ${OBJS} ${MAINOBJ} -o ${NAME}
	
all: ${NAME}

clean:
	rm -rf ${OBJS} ${MAINOBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re