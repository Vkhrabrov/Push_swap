# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:35:04 by vkhrabro          #+#    #+#              #
#    Updated: 2023/07/11 00:28:06 by vkhrabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
LIBS = libft/
MAKE = make

SRC_F:= push_swap ps_utilities ps_utilities_2 ps_utilities_3 ps_commands ps_commands_2 algo algo_2 

FLAGS = -Wall -Wextra -Werror -g -MMD
RM = rm -f
SRC = $(addsuffix .c, $(SRC_F))
OBJS = $(SRC:.c=.o)
DEPS = $(OBJS:.o=.d)

CC = gcc

%.o: %.c 
	@$(CC) $(FLAGS) -c $< -o $@

all: make_libs $(NAME)
	@echo "\033[1;32mThe project has been compiled successfully\033[0m"

make_libs:
	@$(MAKE) -C $(LIBS)
	@echo "\033[1;32mLibraries have been compiled successfully\033[0m"

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(FLAGS) -L$(LIBS) -lft -o $@ $(OBJS)

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) -C $(LIBS) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBS) fclean

re: fclean all

.PHONY: re clean fclean all

-include $(DEPS)

