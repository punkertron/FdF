# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 18:01:46 by drohanne          #+#    #+#              #
#    Updated: 2021/10/10 18:49:41 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= ft_split.c ft_strjoin.c ft_strnstr.c \
				ft_strlen.c ft_putstr_fd.c ft_strncmp.c

SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

OBJ_FILES	= $(SRC_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))


NAME		= libft.a
INCLUDE		= -I ./includes

CC			= gcc
LIBC		= ar rcs
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g $(INCLUDE)

$(NAME):	$(OBJS)
			@${LIBC} ${NAME} ${OBJS}

all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c includes/libft.h 
					@mkdir -p objs
					@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
			@${RM} ${OBJS_DIR}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re