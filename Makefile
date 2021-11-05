# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 21:43:59 by drohanne          #+#    #+#              #
#    Updated: 2021/11/05 22:21:35 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= main.c get_next_line.c get_next_line_utils.c map.c \
				draw.c draw_utils.c draw_utils2.c rotate.c instructions.c \
				colour.c
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs


OBJ_FILES	= $(SRC_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= fdf
INCLUDE		= -I ./includes
DEPS		= $(OBJS:.o=.d)
LIBFT_DIR	= ./libft

CC			= clang
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -march=native -O2
LIB			= -L$(LIBFT_DIR) -lft -L./libmlx -lmlx -lXext -lX11 -lm
LIBFT_A		= $(LIBFT_DIR)/libft.a

$(NAME):	$(LIBFT_A) $(OBJS)
			${CC} ${CFLAGS} ${OBJS} $(INCLUDE) ${LIB} -o ${NAME}

$(LIBFT_A):	
			@${MAKE} -C $(LIBFT_DIR)

all:		$(NAME)

-include $(DEPS)
$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
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