# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 15:03:21 by kgezgin           #+#    #+#              #
#    Updated: 2023/12/20 15:44:29 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR = objs

SRCS = main.cpp Mandatory.cpp\

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

NAME = Identify

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98  -g #-fsanitize=address


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -MMD -o $(NAME)

$(OBJS_DIR)/%.o : %.cpp | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJS) $(OBJS_DIR) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re

-include $(DEPS)