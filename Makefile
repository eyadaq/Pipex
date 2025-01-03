# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 06:51:34 by eaqrabaw          #+#    #+#              #
#    Updated: 2025/01/01 02:16:20 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = pipex
CC = cc
Flags = -Wall -Wextra -Werror
SRCS = main utilities extra_utils
srcDir = srcs/
incDir = includes/
objDir = obj/
libftDir = $(incDir)/libft
INCs = pipex.h
Srcs = $(addprefix $(srcDir), $(addsuffix .c, $(SRCS)))
OBJ = $(Srcs:$(srcDir)%.c=$(objDir)%.o)
INC = $(addprefix $(incDir), $(INCs))

all : $(Name)

$(Name) : $(OBJ) $(libftDir)/libft.a
	$(CC) $(Flags) -o $(Name) $(OBJ) -L$(libftDir) -lft

$(objDir)%.o: $(srcDir)%.c $(INC) | $(objDir)
	@$(CC) $(Flags) -c $< -o $@

$(objDir):
	@mkdir -p $(objDir)

clean :
	@rm -rf $(objDir)
	$(MAKE) -C $(libftDir) clean

fclean : clean
	@rm -f $(Name)
	$(MAKE) -C $(libftDir) fclean

re : fclean all
	$(MAKE) -C $(libftDir) re

$(libftDir)/libft.a:
	$(MAKE) -C $(libftDir)

.PHONY : all clean fclean re
