# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 23:21:58 by eaqrabaw          #+#    #+#              #
#    Updated: 2025/02/11 07:32:36 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = libft.a
CC = cc
AR = ar rcs
Flags = -Wall -Wextra -Werror
GREEN   	= \033[0;32m
RED    		= \033[0;31m
RESET   	= \033[0m
ARROW   	= ✔
SRC =	ft_atoi \
		ft_atol \
		ft_bzero \
		ft_calloc \
		ft_freedouble \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_lstadd_back \
		ft_lstadd_front \
		ft_lstclear \
		ft_lstdelone \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_lstsize \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_printf \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_puthexa \
		ft_putnbr_fd \
		ft_putptr \
		ft_putstr_fd \
		ft_putstr_printf \
		ft_putunsigned \
		ft_split\
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi\
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		get_next_line

srcDir = src/
headersDIR = headers/
objDir = obj/
SRCS = $(addprefix $(srcDir), $(addsuffix .c, $(SRC)))
OBJS = $(SRCS:$(srcDir)%.c=$(objDir)%.o)

# Default target
all: $(Name)

# Rule for creating the static library
$(Name): $(OBJS)
	@echo "$(GREEN)Making $(Name)...$(RESET)"
	@$(AR) $(Name) $(OBJS)
	@echo "$(GREEN)Done $(ARROW)$(RESET)"

# Rule to create object files in the objDir
$(objDir)%.o: $(srcDir)%.c | $(objDir)
	@$(CC) $(Flags) -c $< -o $@

# Create the object directory if it doesn't exist
$(objDir):
	@mkdir -p $(objDir)

# Clean object files
clean:
	@echo "$(RED)Deleting  Libft $(objDir) files...$(RESET)"
	@rm -rf $(objDir)
	@echo "$(RED)Done $(ARROW)$(RESET)"

# Clean everything (object files + library)
fclean: clean
	@echo "$(RED)Deleting $(Name)...$(RESET)"
	@rm -f $(Name)
	@echo "$(RED)Done $(ARROW)$(RESET)"

# Rebuild everything (clean + all)
re: fclean all

.PHONY: all clean fclean re
