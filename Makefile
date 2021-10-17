# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 21:43:59 by drohanne          #+#    #+#              #
#    Updated: 2021/10/10 18:47:39 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= main.c get_next_line.c get_next_line_utils.c
SRC_FILES_B	= 
SRCS_DIR	= ./srcs
SRCS_DIR_B	= ./srcs_b
OBJS_DIR	= ./objs
OBJS_DIR_B	= ./objs


OBJ_FILES	= $(SRC_FILES:.c=.o)
OBJ_FILES_B	= $(SRC_FILES_B:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

SRCS_B 		= $(addprefix $(SRCS_DIR_B)/, $(SRC_FILES_B))
OBJS_B		= $(addprefix $(OBJS_DIR_B)/, $(OBJ_FILES_B))


NAME		= fdf
INCLUDE		= -I ./includes
INCLUDE_B	= -I ./includes_b

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g #$(INCLUDE)
LIB			= -L. -lft
LIBFT_A		= ./libft/libft.a

$(NAME):	$(LIBFT_A) $(OBJS)
			${CC} ${CFLAGS} ${OBJS} $(INCLUDE) ${LIB} -o ${NAME}

$(LIBFT_A):
			@${MAKE} all -C ./libft
			cp libft/libft.a ./

all:		$(NAME)

bonus:		$(LIBFT_A) $(OBJS_B)
			@cp libft/libft.a ./
			${CC} ${CFLAGS} ${OBJS_B} $(INCLUDE_B) ${LIB} -o ${NAME}

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c includes/fdf.h 
					@mkdir -p objs
					$(CC) -c $(CFLAGS) $(INCLUDE) ${LIB} $< -o $@

$(OBJS_DIR_B)/%.o :	$(SRCS_DIR_B)/%.c includes_b/pipex_bonus.h 
					@mkdir -p objs
					$(CC) -c $(CFLAGS) $(INCLUDE_B) $< -o $@

clean:
			${RM} ${OBJS_DIR}
			@${MAKE} clean -C ./libft

fclean:		clean
			${RM} ${NAME}
			@${MAKE} fclean -C ./libft
			@${RM} libft.a

re:			fclean all

.PHONY:		all clean fclean re