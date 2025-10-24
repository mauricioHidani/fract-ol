/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:21:26 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/24 14:53:11 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_render_mandelbrot(t_app *app);
static void	ft_setpxl_julia(t_vector2 d, t_graph *graph, t_fractal *fractal);
static int	ft_keyboard_hook(int keycode, void *param);
static int	ft_mouse_hook(int mouse, int x, int y, t_app *param);

void	ft_fractal_mandelbrot(char **argv)
{
	t_app		*app;
	t_fractal	*fractal;
	t_vector2	min;
	t_vector2	imag;

	app = ft_new_app(argv);
	min = ft_new_vector2(-2.5, -1.5);
	imag = ft_new_vector2(1.5, 1.5);
	fractal = ft_new_fractal(min, imag, app);
	ft_render_mandelbrot(app);
	mlx_key_hook(app->graph->win, ft_keyboard_hook, app);
	mlx_mouse_hook(app->graph->win, ft_mouse_hook, app);
	mlx_hook(app->graph->win, 17, 0, ft_close_win, app);
	mlx_loop(app->mlx);
}

static void	ft_render_mandelbrot(t_app *app)
{
	t_vector2	display;

	display = ft_new_vector2(0, 0);
	while (display.y < HEIGHT)
	{
		display.x = 0;
		while (display.x < WIDTH)
		{
			ft_setpxl_julia(display, app->graph, app->fractal);
			display.x++;
		}
		display.y++;
	}
	mlx_put_image_to_window(app->mlx, app->graph->win, app->graph->img, 0, 0);
}

// f(z) = z^2 + c
static void	ft_setpxl_julia(t_vector2 d, t_graph *grp, t_fractal *frc)
{
	t_vector2	aux;
	int			color;
	int			i;

	color = 0x101010;
	i = 0;
	frc->z = ft_new_vector2(0, 0);
	frc->c.x = frc->min.x + d.x * (frc->max.x - frc->min.x) / WIDTH;
	frc->c.y = frc->min.y + d.y * (frc->max.y - frc->min.y) / HEIGHT;
	while (i < frc->iter)
	{
		if ((frc->z.x * frc->z.x + frc->z.y * frc->z.y) > 4)
		{
			color = ft_build_color((double)i, frc->z, frc);
			ft_put_pixel(d, color, grp);
			return ;
		}
		aux.x = frc->z.x * frc->z.x - frc->z.y * frc->z.y + frc->c.x;
		aux.y = 2 * frc->z.x * frc->z.y + frc->c.y;
		frc->z = aux;
		i++;
	}
	ft_put_pixel(d, color, grp);
}

static int	ft_keyboard_hook(int keycode, void *param)
{
	ft_handle_keyboard(keycode, param);
	ft_render_mandelbrot((t_app *)param);
	return (0);
}

static int	ft_mouse_hook(int keycode, int x, int y, t_app *param)
{
	t_vector2	mouse_pos;

	mouse_pos.x = (double)x;
	mouse_pos.y = (double)y;
	if (ft_handle_mouse(keycode, mouse_pos, param))
	{
		ft_render_mandelbrot(param);
		return (0);
	}
	return (1);
}
