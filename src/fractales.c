/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urdliz.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:21:31 by davmoren          #+#    #+#             */
/*   Updated: 2024/11/28 01:36:34 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(Fractal fractal, double cx, double cy) {
    double tmp;
    int i = 0;

    fractal.zx = cx;
    fractal.zy = cy;

    while (i < fractal.iteraciones) {
        // Calcula las nuevas coordenadas
        tmp = fractal.zx * fractal.zx - fractal.zy * fractal.zy + fractal.cx;
        fractal.zy = 2.0 * fractal.zx * fractal.zy + fractal.cy;
        fractal.zx = tmp;

        if (fractal.zx * fractal.zx + fractal.zy * fractal.zy > 4.0) {
            break;
        }
        i++;
    }
    return i;  
}


int mandelbort(Fractal fractal, int interaction) {
    double tmp;
    int i = 0;

    fractal.zx = 0.0;
    fractal.zy = 0.0;

    while (i < interaction) {
        tmp = fractal.zx * fractal.zx - fractal.zy * fractal.zy + fractal.cx;
        fractal.zy = 2.0 * fractal.zx * fractal.zy + fractal.cy;
        fractal.zx = tmp;

        if (fractal.zx * fractal.zx + fractal.zy * fractal.zy > 4.0) {
            break;
        }
        printf("Iteración: %d, zx: %f, zy: %f\n", i, fractal.zx, fractal.zy);

        i++;
        
    }
    return i; 
}
