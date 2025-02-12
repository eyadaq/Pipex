# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 06:51:34 by eaqrabaw          #+#    #+#              #
#    Updated: 2025/02/12 10:41:03 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ARROW = ✔

INC = includes/pipex.h
SRC_DIR = srcs/
OBJ_DIR = obj/
BONUS_DIR = bonus/
B_OBJ_DIR = obj_bonus/
LIBFT_DIR = includes/libft

# Source files (without path)
SRCS = 	main\
		extra_utils \
		utilities

OBJS = $(SRCS:%=$(OBJ_DIR)%.o)

# Bonus source files (without path)
BONUS_SRCS = bonus extra_utils utilities
BONUS_OBJS = $(BONUS_SRCS:%=$(B_OBJ_DIR)%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)Done!$(RESET)"

# Ensure OBJ_DIR exists before compilation
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Compiling $< $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus: $(BONUS_OBJS) $(LIBFT_DIR)/libft.a
	@echo "$(GREEN)Compiling $(NAME) (bonus)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)Done!$(RESET)"

# Ensure B_OBJ_DIR exists before bonus compilation
$(B_OBJ_DIR)%.o: $(BONUS_DIR)%.c $(INC) | $(B_OBJ_DIR)
	@mkdir -p $(B_OBJ_DIR)
	@echo "$(GREEN)Compiling $< $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) | $(B_OBJ_DIR)
	@mkdir -p $(B_OBJ_DIR)
	@echo "$(GREEN)Compiling $< $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR):
	@mkdir -p $(B_OBJ_DIR)

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR) $(B_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)Done $(ARROW)$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Done $(ARROW)$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
