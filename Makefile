# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 15:20:39 by mal-mora          #+#    #+#              #
#    Updated: 2024/03/09 11:34:44 by mal-mora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_split.c parsing.c push_swap.c stack_utils.c string_utils.c \
		my_free.c push_ops.c reverse_ops.c rotate_ops.c swap_ops.c sorting_stack.c \
		algo_utils.c sort_min_nbrs.c

OBJS = $(SRCS:.c=.o)

TARGET = push_swap

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(TARGET) 

re :
	fclean all
	