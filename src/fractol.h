/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urdliz.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:21:19 by davmoren          #+#    #+#             */
/*   Updated: 2024/12/02 18:54:36 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef  FRACTOL_H
# define FRACTOL_H

#include "../lib/LIBFT/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/LIBFT/FT_PRINTF/src/ft_printf.h" 
//#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>  
#include <math.h>
#define MAX_ITER 10000
#define MAX_ARG_SIZE 30


typedef struct s_tipofractal
{
    char *JULIA;
    char *MANDELBROT;
    
} TipoFractal;




 typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct {
    void *mlx;
    int ancho;
    int alto;
    int posx;
    int posy;
    int bpp;
    int size_line;
    int endian;
    char *data;
    void *win;
    void *img;
    int key_press;
} Ventana;
typedef struct{
	TipoFractal type;
	int widht;
	int height;
	int interaction;
	char *color;
	int x;
	int y;
    
} comand;
typedef struct {
    int min_x;
    int max_x;
    int max_y;
    int min_y;
    int is_dragging;
    int last_mouse_x;
    int last_mouse_y;
}   mouse;
typedef struct {
    TipoFractal tipo;
    double c;
    int iteraciones;
    int x;
    int y;
    double cx;
    double cy;
    double zy;
    double zx;
    int zoom;
    int offset;
    comand *comand;
    Ventana *Ventana;
} Fractal;
typedef struct s_data {
    mouse mouse;
    comand comand;
    Fractal fractal;
    Ventana ventana;
} t_data;


void tipo_fractal(TipoFractal *tipo, int i, char *str);
int julia(Fractal fractal, double cx, double cy);
int mandelbort(Fractal fractal, int iteraction);
void draw_fractal(Ventana ventana, Fractal fractal, comand *comand);
char *select_type(char *str,int i);
void add_command(char *argfind, comand *comand, int i, char **av,TipoFractal *tipo);
comand *arguments(int ac,  char **av, comand *comand, TipoFractal *tipo);
int mouse_press(int button, int x, int y, t_data *data);

#endif
