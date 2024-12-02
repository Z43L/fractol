#include "fractol.h"
#include <stdio.h>
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
    // Declaración de estructuras necesarias
    Ventana ventana;
    Fractal fractal;
    TipoFractal tipo;

    


    if (ac < 2) {
        printf("Uso: ./fractol type [JULIA/MANDELBROT] interactions [iteraciones] widht [ancho] height [alto]\n");
        return 1;
    }


    comand *cmd = (comand *)calloc(1, sizeof(comand));
    if (!cmd) {
        printf("Error: No se pudo asignar memoria para los comandos.\n");
        return 1;
    }

    cmd->type.JULIA = "JULIA";
    cmd->type.MANDELBROT = "MANDELBROT";
    cmd->widht = 800;   
    cmd->height = 600;   
    cmd->interaction = MAX_ITER; 

  
    arguments(ac, av, cmd, &tipo);
    if (!cmd->type.JULIA && !cmd->type.MANDELBROT) {
        printf("Error: Tipo de fractal no válido. Usa 'JULIA' o 'MANDELBROT'.\n");
        free(cmd);
        return 1;
    }


    ventana.ancho = cmd->widht;
    ventana.alto = cmd->height;
    ventana.mlx = mlx_init();
    if (!ventana.mlx) {
        printf("Error: No se pudo inicializar la biblioteca MiniLibX.\n");
        free(cmd);
        return 1;
    }

    ventana.win = mlx_new_window(ventana.mlx, ventana.ancho, ventana.alto, "Fractal");
    if (!ventana.win) {
        printf("Error: No se pudo crear la ventana.\n");
        free(cmd);
        return 1;
    }

    ventana.img = mlx_new_image(ventana.mlx, ventana.ancho, ventana.alto);
    if (!ventana.img) {
        printf("Error: No se pudo crear la imagen.\n");
        free(cmd);
        return 1;
    }

    ventana.data = mlx_get_data_addr(ventana.img, &ventana.bpp, &ventana.size_line, &ventana.endian);

    fractal.iteraciones = cmd->interaction;
    fractal.zoom = 1.0; 
    fractal.offset = 0.0; 

    draw_fractal(ventana, fractal, cmd);

  
    mlx_put_image_to_window(ventana.mlx, ventana.win, ventana.img, 0, 0);

 
    mlx_loop(ventana.mlx);

   
    free(cmd);
    return 0;
}
