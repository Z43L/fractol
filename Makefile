# Nombre del proyecto
NAME = fractol

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror

# Bibliotecas y includes
LIBS_MLX = $(MLXDIR)/libmlx.a -lXext -lX11 -lm
LIBS_LIBFT = $(LIBFTDIR)/libft.a
INCLUDES_MLX = -Imlx_linux
INCLUDES_LIBFT = -Ilibft

# Directorios
SRCDIR = src
OBJDIR = obj
LIBFTDIR = lib/LIBFT
MLXDIR = lib/minilibx-linux
# Fuentes y objetos
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Regla por defecto
all: $(NAME)

# Regla para el ejecutable
$(NAME): $(OBJS) $(LIBFTDIR)/libft.a
	$(CC) $(OBJS) $(LIBS_LIBFT) $(LIBS_MLX) -o $(NAME)

# Regla para los objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)  # Crea el directorio de objetos si no existe
	$(CC) $(CFLAGS) $(INCLUDES_MLX) $(INCLUDES_LIBFT) -c $< -o $@

# Regla para las bibliotecas de libft
$(LIBFTDIR)/libft.a:
	make -C $(LIBFTDIR)

# Limpiar archivos temporales
clean:
	rm -rf $(OBJDIR)/*.o
	make -C $(LIBFTDIR) clean

# Eliminar todos los archivos generados por el Makefile
fclean: clean
	rm -rf $(NAME)

# Reconstruir todo
re: fclean all
