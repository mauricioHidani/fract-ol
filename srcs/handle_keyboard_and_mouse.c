/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard_and_mouse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:22:35 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/24 15:30:02 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calc_shift(double *real, double *imag, int direction);

void	ft_handle_keyboard(int keycode, void *param)
{
	t_fractal *fractal;

	fractal = ((t_app *)param)->fractal;
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
		ft_calc_shift(&fractal->min.x, &fractal->max.x, -1);
	else if (keycode == XK_Right)
		ft_calc_shift(&fractal->min.x, &fractal->max.x, 1);
	if (keycode == XK_Up)
		ft_calc_shift(&fractal->min.y, &fractal->max.y, -1);
	else if (keycode == XK_Down)
		ft_calc_shift(&fractal->min.y, &fractal->max.y, 1);
}

t_bool	ft_handle_mouse(int keycode, t_vector2 mouse_pos, void *param)
{
	t_fractal	*frc;
	double		mouse_re;
	double		mouse_im;
	double		zoom;

	frc = ((t_app *)param)->fractal;
	if (keycode == 4)
		zoom = ZOOM_IN_FACTOR;
	else if (keycode == 5)
		zoom = ZOOM_OUT_FACTOR;
	else
		return (FALSE);
	mouse_re = frc->min.x + mouse_pos.x * (frc->max.x - frc->min.x) / WIDTH;
	mouse_im = frc->min.y + mouse_pos.y * (frc->max.y - frc->min.y) / HEIGHT;
	frc->min.x = mouse_re + (frc->min.x - mouse_re) * zoom;
	frc->max.x = mouse_re + (frc->max.x - mouse_re) * zoom;
	frc->min.y = mouse_im + (frc->min.y - mouse_im) * zoom;
	frc->max.y = mouse_im + (frc->max.y - mouse_im) * zoom;
	return (TRUE);
}

static void	ft_calc_shift(double *real, double *imag, int direction)
{
	double	shift;
	
	shift = (*imag - *real) * SHIFT_FACTOR;
	*real += (shift * direction);
	*imag += (shift * direction);
}
