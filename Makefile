# Nombre del proyecto
NAME = fractol

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror

# Bibliotecas y includes
LIBS_MLX = -lmlx_Linux -L/path/to/minilibx-linux -lm -lX11 -lXext
LIBS_LIBFT = -Llibft -lft
INCLUDES_MLX = -I/path/to/minilibx-linux
INCLUDES_LIBFT = -Llibft -Ilibft

# Directorios
SRCDIR = src
OBJDIR = obj
LIBFTDIR = libft

# Fuentes y objetos
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Regla por defecto
all: $(NAME)

# Regla para el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS_MLX) $(LIBS_LIBFT)

# Regla para los objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES_MLX) -c $< -o $@

# Regla para las bibliotecas de libft
$(LIBFTDIR)/libft.a:
	make -C $(LIBFTDIR)

# Limpiar archivos temporales
clean:
	rm -rf $(OBJDIR)/*.o $(NAME)
	make -C $(LIBFTDIR) clean

# Eliminar todos los archivos generados por el Makefile
fclean: clean
	rm -rf $(NAME)

# Reconstruir todo
re: fclean all
