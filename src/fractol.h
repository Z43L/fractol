/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:21:19 by davmoren          #+#    #+#             */
/*   Updated: 2024/11/03 18:03:31 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef  FRACTOL_H
# define FRACTOL_H

#include "../lib/LIBFT/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/LIBFT/ft_get_next_line/get_next_line.h"
#include "../lib/LIBFT/FT_PRINTF/src/ft_printf.h" 
#include <math.h>


typedef enum {
    JULIA,
    MANDELBROT,
    SIERPINSKI,
    SNOWFLAKE
} TipoFractal;

typedef struct {
    TipoFractal tipo;
    double c;
    int iteraciones;
} Fractal;

 typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct {
    int ancho;
    int alto;
    int posx;
    int posy;
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

void tipo_fractal(TipoFractal *tipo, int i, char *str);

#endif
