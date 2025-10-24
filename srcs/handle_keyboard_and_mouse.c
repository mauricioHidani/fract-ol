/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard_and_mouse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:22:35 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/23 20:19:00 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handle_keyboard(int keycode, void *param)
{
	t_fractal *fractal;

	fractal = ft_get_app(param)->fractal;
	if (keycode == XK_Escape)
		ft_close_win(param);
	if (keycode == XK_plus || keycode == XK_KP_Add)
		fractal->iter += RESOLUTION_FACTOR;
	else if (keycode == XK_minus || keycode == XK_KP_Subtract)
		fractal->iter -= RESOLUTION_FACTOR;
	if (keycode == XK_bracketright)
		fractal->color_phase += COLOR_FACTOR;
	else if (keycode == XK_bracketleft)
		fractal->color_phase -= COLOR_FACTOR;
	if (keycode == 65105)
		fractal->color_factor += 0.01;
	else if (keycode == 65107)
		fractal->color_factor -= 0.01;
	if (keycode == XK_Left)
		ft_shift_proportional(&fractal->min, SHIFT_FACTOR);
	else if (keycode == XK_Right)
		ft_shift_proportional(&fractal->min, -SHIFT_FACTOR);
	if (keycode == XK_Up)
		ft_shift_proportional(&fractal->max, SHIFT_FACTOR);
	else if (keycode == XK_Down)
		ft_shift_proportional(&fractal->max, -SHIFT_FACTOR);
}

t_bool	ft_handle_mouse(int keycode, t_vector2 mouse_pos, void *param)
{
	t_fractal	*frc;
	double		mouse_re;
	double		mouse_im;
	double		zoom;

	frc = ft_get_app(param)->fractal;
	if (keycode == 4)
		zoom = ZOOM_IN_FACTOR;
	else if (keycode == 5)
		zoom = ZOOM_OUT_FACTOR;
	else
		return (FALSE);
	mouse_re = frc->min.x + mouse_pos.x / WIDTH * (frc->min.y - frc->min.x);
	mouse_im = frc->max.x + mouse_pos.y / HEIGHT * (frc->max.y - frc->max.x);
	frc->min.x = mouse_re + (frc->min.x - mouse_re) * zoom;
	frc->min.y = mouse_re + (frc->min.y - mouse_re) * zoom;
	frc->max.x = mouse_im + (frc->max.x - mouse_im) * zoom;
	frc->max.y = mouse_im + (frc->max.y - mouse_im) * zoom;
	return (TRUE);
}
