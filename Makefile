# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 02:29:13 by drohanne          #+#    #+#              #
#    Updated: 2021/11/06 18:32:59 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= main.c get_next_line.c get_next_line_utils.c map.c \
				draw.c draw_utils.c draw_utils2.c rotate.c instructions.c \
				hook.c colour.c sin_cos.c
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs


OBJ_FILES	= $(SRC_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= fdf
INCLUDE		= -I ./includes
DEPS		= $(OBJS:.o=.d)
LIBFT_DIR	= ./libft
LMLX_DIR	= ./libmlx

CC			= clang
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g3 #-MMD -MP -march=native -O2
LIB			= -L$(LIBFT_DIR) -lft -L$(LMLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_A		= $(LIBFT_DIR)/libft.a

all bonus:
			@${MAKE} -C $(LMLX_DIR)
			@${MAKE} -C $(LIBFT_DIR)
			@${MAKE} $(NAME)

$(NAME):	$(LIBFT_A) $(OBJS)
			${CC} ${CFLAGS} ${OBJS} $(INCLUDE) ${LIB} -o ${NAME}

$(LIBFT_A):	
			${MAKE} -C $(LIBFT_DIR)

-include $(DEPS)
$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
					@mkdir -p objs
					$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
			${RM} ${OBJS_DIR}
			@${MAKE} clean -C ${LIBFT_DIR}
			@${MAKE} clean -C $(LMLX_DIR)

fclean:		clean
			${RM} ${NAME}
			${RM} ${LMLX_DIR}/libmlx.a
			@${MAKE} fclean -C ${LIBFT_DIR}

re:			fclean all

.PHONY:		all bonus clean fclean re