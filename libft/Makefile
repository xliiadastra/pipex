# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 15:18:40 by yichoi            #+#    #+#              #
#    Updated: 2021/12/06 19:25:43 by yichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rcs

RM			= rm
RMFLAGS		= -f

INCLUDES	= ./libft.h

SRCS		=	ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strnstr.c	\
				ft_strncmp.c	\
				ft_atoi.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_isspace.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_striteri.c

SRCS_BN		=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BN:.c=.o)

ifdef WITH_BONUS
A_OBJS = $(OBJS) $(OBJS_BONUS)
else
A_OBJS = $(OBJS)
endif

.PHONY : all
all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(A_OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : clean
clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

.PHONY : re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : bonus
bonus :
	$(MAKE) WITH_BONUS=1 all
