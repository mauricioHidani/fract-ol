/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:21:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/25 13:39:41 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_setpxl_julia(t_vector2 d, t_graph *grp, t_fractal *f);
static int	ft_keyboard_hook(int keycode, void *param);
static int	ft_mouse_hook(int mouse, int x, int y, t_app *param);

void	ft_fractal_julia(char **argv)
{
	t_app		*app;
	t_fractal	*fractal;
	t_vector2	min;
	t_vector2	max;

	app = ft_new_app(argv);
	min = ft_new_vector2(-2.0, -2.0);
	max = ft_new_vector2(2.0, 2.0);
	fractal = ft_new_fractal(min, max, app);
	fractal->c = ft_input_julia_complex(argv[2], argv[3], app);
	ft_render(app, ft_setpxl_julia);
	mlx_key_hook(app->graph->win, ft_keyboard_hook, app);
	mlx_mouse_hook(app->graph->win, ft_mouse_hook, app);
	mlx_hook(app->graph->win, 17, 0, ft_close_win, app);
	mlx_loop(app->mlx);
}

// f(z) = z^2 + c
static void	ft_setpxl_julia(t_vector2 d, t_graph *grp, t_fractal *frc)
{
	t_vector2	aux;
	int			color;
	int			i;

	color = 0x101010;
	frc->z.x = frc->min.x + d.x * (frc->max.x - frc->min.x) / WIDTH;
	frc->z.y = frc->min.y + d.y * (frc->max.y - frc->min.y) / HEIGHT;
	i = 0;
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
	ft_render((t_app *)param, ft_setpxl_julia);
	return (0);
}

static int	ft_mouse_hook(int keycode, int x, int y, t_app *param)
{
	t_vector2	mouse_pos;

	mouse_pos.x = (double)x;
	mouse_pos.y = (double)y;
	if (ft_handle_mouse(keycode, mouse_pos, param))
	{
		ft_render(param, ft_setpxl_julia);
		return (0);
	}
	return (1);
}
