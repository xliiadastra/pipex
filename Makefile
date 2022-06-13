# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 18:31:45 by yichoi            #+#    #+#              #
#    Updated: 2022/06/13 17:59:40 by yichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

BONUS_NAME = ./pipex_bonus/pipex

SRCS =	pipex.c		\
		pipex_utils.c	\
		pipex_process.c
BONUS_SRCS = ./pipex_bonus/pipex_bonus.c			\
			 ./pipex_bonus/pipex_utils_bonus.c		\
			 ./pipex_bonus/pipex_process_bonus.c

OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

HDR = ./pipex.h	\
	  ./pipex_bonus/pipex_bonus.h

LIB_DIR = ./libft
LIB_NAME = ft
LIB = $(LIB_DIR)/lib$(LIB_NAME).a

INCLUDES = -I$(HDR) -I$(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):$(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS) -o $(NAME)

$(LIB):
	make -C $(LIB_DIR) bonus

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIB) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -l$(LIB_NAME) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: fclean all clean re bonus
