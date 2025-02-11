# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 06:51:34 by eaqrabaw          #+#    #+#              #
#    Updated: 2025/02/11 07:18:46 by eaqrabaw         ###   ########.fr        #
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
GREEN   	= \033[0;32m
RED    		= \033[0;31m
RESET   	= \033[0m
ARROW   	= ✔

all : $(Name)

$(Name) : $(OBJ) $(libftDir)/libft.a
	@echo "$(GREEN)Making $(Name)...$(RESET)"
	@$(CC) $(Flags) -o $(Name) $(OBJ) -L$(libftDir) -lft
	@echo "$(GREEN)Done $(ARROW)$(RESET)"

$(objDir)%.o: $(srcDir)%.c $(INC) | $(objDir)
	@echo "$(GREEN)Generating $@ $(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Done $(ARROW)$(RESET)"

$(objDir):
	@echo "$(GREEN)Creating OBJ_DIR$(RESET)"
	@mkdir -p $(objDir)
	@echo "$(GREEN)Done $(ARROW)$(RESET)"

clean :
	@echo "$(RED)Deleting $(Name) $(objDir) file $(RESET)"
	@rm -rf $(objDir)
	@$(MAKE) -C $(libftDir) clean
	@echo "$(RED)Done $(ARROW)$(RESET)"

fclean : clean
	@echo "$(RED)Deleting $(Name)...$(RESET)"
	@rm -f $(Name)
	@$(MAKE) -C $(libftDir) fclean
	@echo "$(RED)Done $(ARROW)$(RESET)"

re : fclean all

$(libftDir)/libft.a:
	@$(MAKE) -C $(libftDir)

.PHONY : all clean fclean re
