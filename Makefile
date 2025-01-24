CC = cc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g
NAME = pipex
SRC = pipex.c \
	utils.c \
	path.c \

OBJ = $(SRC:.c=.o)

LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf

LIBFT = $(LIBFT_PATH)/libft.a
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

# Cible principale
all: $(NAME)

# Construction de l'exécutable en respectant les dépendances
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Compiling libraries..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "libraries compiled successfully!"

# Compilation des bibliothèques externes
$(LIBFT):
	@make -s -C $(LIBFT_PATH) bonus

$(FT_PRINTF):
	@make -s -C $(FT_PRINTF_PATH)

# Compilation des fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(LIBFT_PATH) -I$(FT_PRINTF_PATH) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJ)
	@make -s -C $(LIBFT_PATH) clean
	@make -s -C $(FT_PRINTF_PATH) clean

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(FT_PRINTF_PATH) fclean

# Rebuild complet
re: fclean all
