# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:35:04 by vkhrabro          #+#    #+#              #
#    Updated: 2023/06/05 18:54:19 by vkhrabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
#HEADER_B = pipex_bonus.h
LIBS = libft/
MAKE = make bonus

SRC_F:= push_swap ps_utilities ps_commands ps_commands_2 algo

#SRC_BNS_F:= pipex_bonus pipex_utils_bonus pipex_utils_2_bonus pipex_utils_3_bonus get_next_line/get_next_line get_next_line/get_next_line_utils

FLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRC = $(addsuffix .c, $(SRC_F))
OBJS = $(SRC:.c=.o)
#SRC_BNS = $(addsuffix .c, $(SRC_BNS_F))
#OBJS_BNS = $(SRC_BNS:.c=.o)

CC = gcc

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: 	make_libs $(NAME)

make_libs:
	$(MAKE) -C $(LIBS)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) -L$(LIBS) -lft -o $@ $(OBJS)

#bonus: make_libs $(OBJS_BNS) $(HEADER_B)
#	$(CC) $(FLAGS) -L$(LIBS) -lft -o $(NAME) $(OBJS_BNS)

clean:
	$(RM) $(OBJS) 
	$(MAKE) -C $(LIBS) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBS) fclean

re: fclean all

.PHONY: re clean fclean all