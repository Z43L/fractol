/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:53 by davmoren          #+#    #+#             */
/*   Updated: 2024/11/03 18:04:18 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <linux/limits.h>

char *select_type(char *str,int i, char **argdevu)
{
	char *arg[7] = {"type", "widht", "height","interactions","color","puntox","puntoy"};
	int j;
	char *argfind;
	if(str[i] == '-')
	{
		j = i;
		while(str[j] != ' ')
		{
			int k = 0;
			argfind[k] = str[j];
			k++;
			j++;
		}
		i = j;
		j =0;
		while(arg[j])
		{
			if(ft_strncmp(arg[j], argfind, ft_strlen(argfind)) ==0)
			{
				
				return argfind;
			}
			j++;
		}		
	}
	return NULL;
}

void add_command(char *argfind, comand comand, int i, char **av,TipoFractal *tipo)
{
	if(ft_strncmp(argfind, "type", ft_strlen("type")) == 0)
	{
		i++;
		tipo_fractal(tipo, 0, av[i]);
		
	}
	else if(ft_strncmp(argfind, "widht", ft_strlen("widht")) == 0)
	{
		i++;
		comand.widht = ft_atoi(av[i]);
	}
	else if(ft_strncmp(argfind, "height", ft_strlen("height")) == 0)
	{
		i++;
		comand.height = ft_atoi(av[i]);
	}
	else if(ft_strncmp(argfind, "x", ft_strlen("x")) == 0)
	{
		i++;
		comand.x = ft_atoi(av[i]);
	}
	else if(ft_strncmp(argfind, "y", ft_strlen("y")) == 0)
	{
		i++;
		comand.y = ft_atoi(av[i]);
	}
	else if(ft_strncmp(argfind, "interactions", ft_strlen("interactions")) == 0)
	{
		i++;
		comand.interaction = ft_atoi(av[i]);
	}
	else if(ft_strncmp(argfind, "color", ft_strlen("color")) == 0)
	{
		i++;
		comand.color = av[i];
	}
}

void tipo_fractal(TipoFractal *tipo, int i, char *str) {
    int j;
    int k;
    char *fractal;
    while (str[i] == ' ') {
        i++;
    }
    j = i;
    k = 0;
    while (str[j] != ' ') {
        fractal[k++] = str[j++];
    }
    if (ft_strncmp(fractal, "JULIA", ft_strlen("JULIA")) == 0) {
        *tipo = JULIA;
    } else if (ft_strncmp(fractal, "MANDELBROT", ft_strlen("MANDELBROT")) == 0) {
        *tipo = MANDELBROT;
    } else if (ft_strncmp(fractal, "SIERPINSKI", ft_strlen("SIERPINSKI")) == 0) {
        *tipo = SIERPINSKI;
    } else if (ft_strncmp(fractal, "SNOWFLAKE", ft_strlen("snowflake")) == 0) {
        *tipo = SNOWFLAKE;
    }
}

void arguments(char **av, comand comand, TipoFractal *tipo)
{
	char *arg[7] = {"type", "widht", "height","interactions","color","puntox","puntoy"};

	char **argdevu;
	int i;
	char *argfind;	
	i=0;
	
	while(av[i])
	{
		argfind = select_type(av[i], 0, argdevu);
		if(argfind != NULL)
		{
			add_command(argfind,comand, i, av, tipo);
			i++;
		}
		else
			i++;
	}
}



