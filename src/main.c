#include "fractol.h"

int redrawing(t_data *data) {
    mlx_clear_window(data->ventana.mlx, data->ventana.win);
    clear_image(data->ventana);
    draw_fractal(data->ventana, data->fractal, &data->comand);
    mlx_put_image_to_window(data->ventana.mlx, data->ventana.win, data->ventana.img, 0, 0);
    return 0;
}

int close_program(t_data *data) {
    mlx_destroy_window(data->ventana.mlx, data->ventana.win);
    exit(0);
    return 0;
}


int main(int ac, char **av) {
    Ventana ventana;
    Fractal fractal;
    TipoFractal tipo;
    t_data data;

    if (ac < 2) {
        printf("Uso: ./fractol type [JULIA/MANDELBROT] interactions [iteraciones] width [ancho] height [alto]\n");
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

    ventana.ancho = cmd->widht;
    ventana.alto = cmd->height;
    ventana.mlx = mlx_init();
    ventana.win = mlx_new_window(ventana.mlx, ventana.ancho, ventana.alto, "Fractal");
    ventana.img = mlx_new_image(ventana.mlx, ventana.ancho, ventana.alto);
    ventana.data = mlx_get_data_addr(ventana.img, &ventana.bpp, &ventana.size_line, &ventana.endian);

    fractal.iteraciones = cmd->interaction;
    fractal.zoom = 1.0;
    fractal.cx = -0.5;
    fractal.cy = 0.0;

    // Inicializar la estructura de datos
    data.ventana = ventana;
    data.fractal = fractal;
    data.comand = *cmd;
    clear_image(data.ventana);
    draw_fractal(data.ventana, data.fractal, &data.comand);

    // Registrar eventos
    mlx_hook(ventana.win, 4, 1L << 2, mouse_press, &data);
    mlx_loop_hook(ventana.mlx, redrawing, &data);
    mlx_hook(data.ventana.win, 2, 1L << 0, handle_key, &data);
    mlx_hook(data.ventana.win, 17, 0, close_program, &data);

   
    mlx_put_image_to_window(ventana.mlx, ventana.win, ventana.img, 0, 0);

    mlx_loop(ventana.mlx);

    free(cmd);
    return 0;
}
