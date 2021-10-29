# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 21:43:59 by drohanne          #+#    #+#              #
#    Updated: 2021/10/30 00:22:55 by dunstan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= main.c get_next_line.c get_next_line_utils.c map.c \
				draw.c draw_utils.c
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs


OBJ_FILES	= $(SRC_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= fdf
INCLUDE		= -I ./includes

CC			= clang
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g3
LIB			= -L. -lft
LIBFT_A		= ./libft/libft.a

$(NAME):	$(LIBFT_A) $(OBJS)
			${CC} ${CFLAGS} ${OBJS} $(INCLUDE) ${LIB} -o ${NAME}

$(LIBFT_A):
			@${MAKE} all -C ./libft
			cp libft/libft.a ./

all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c includes/fdf.h 
					@mkdir -p objs
					$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
			${RM} ${OBJS_DIR}
			@${MAKE} clean -C ./libft

fclean:		clean
			${RM} ${NAME}
			@${MAKE} fclean -C ./libft
			@${RM} libft.a

re:			fclean all

.PHONY:		all clean fclean re