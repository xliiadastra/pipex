# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 15:18:40 by yichoi            #+#    #+#              #
#    Updated: 2022/06/13 20:43:19 by yichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

BNS_NAME	= ./pipex_bonus/pipex

LIBFT		= ./libft

LIBFT_LIB	= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm
RMFLAGS		= -f

INCLUDES	= ./pipex.h			\
			  ./pipex_bonus/pipex_bonus.h

SRCS		=	pipex.c					\
				pipex_process.c			\
				pipex_utils.c

SRCS_BN		=	./pipex_bonus/pipex_bonus.c			\
				./pipex_bonus/pipex_utils_bonus.c	\
				./pipex_bonus/pipex_process_bonus.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BN:.c=.o)

.PHONY : all
all : $(NAME)

.PHONY : bonus
bonus: $(BNS_NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@ -I./

$(NAME) : $(OBJS)
	@make -C $(LIBFT) 
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT) -lft

$(BNS_NAME): $(OBJS_BONUS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT) -lft

.PHONY : clean
clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(OBJS_BONUS)
	@make fclean -C $(LIBFT)

.PHONY : re
re:
	$(MAKE) fclean
	$(MAKE) all
