# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 18:01:46 by drohanne          #+#    #+#              #
#    Updated: 2021/10/24 16:17:00 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	=	ft_isalnum.c \
			ft_memcpy.c \
			ft_strdup.c \
			ft_strtrim.c \
			ft_isalpha.c \
			ft_memmove.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_isascii.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_tolower.c \
			ft_isdigit.c \
			ft_putchar_fd.c \
			ft_strlcpy.c \
			ft_toupper.c \
			ft_isprint.c \
			ft_putendl_fd.c \
			ft_strlen.c \
			ft_itoa.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_atoi.c \
			ft_memccpy.c \
			ft_putstr_fd.c \
			ft_strncmp.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_split.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_memcmp.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_putchar.c


SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

OBJ_FILES	= $(SRC_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))


NAME		= libft.a
INCLUDE		= -I ./includes

CC			= clang
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