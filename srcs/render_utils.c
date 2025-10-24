/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:28:10 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/24 14:40:02 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render(t_app *app, void (*f)(t_vector2, t_graph *, t_fractal *))
{
	t_vector2	display;

	display = ft_new_vector2(0, 0);
	while (display.y < HEIGHT)
	{
		display.x = 0;
		while (display.x < WIDTH)
		{
			f(display, app->graph, app->fractal);
			display.x++;
		}
		display.y++;
	}
	mlx_put_image_to_window(app->mlx, app->graph->win, app->graph->img, 0, 0);
}

void	ft_put_pixel(t_vector2 v2, int color, t_graph *graph)
{
	int	offset;

	offset = (v2.y * graph->size) + (v2.x * (graph->bpp / 8));
	*(unsigned int *)(graph->addr + offset) = color;
}

int	ft_build_color(double i, t_vector2 z, t_fractal *fractal)
{
	double	smoth;
	double	x;
	double	red;
	double	green;
	double	blue;

	smoth = i + 1 - log(log2(sqrt(pow(z.x, 2) + pow(z.y, 2)))) / log(2);
	x = fmod(smoth * fractal->color_factor + fractal->color_phase, 1);
	if (x < 0)
		x += 1.0;
	red = 9 * (1 - x) * pow(x, 3) * 255;
	green = 15 * pow((1 - x), 2) * pow(x, 2) * 255;
	blue = 8.5 * pow((1 - x), 3) * x * 255;
	return (((int)red << 16) | ((int)green << 8) | ((int)blue));
}
