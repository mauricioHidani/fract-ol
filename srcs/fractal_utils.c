/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:34:16 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/24 14:53:11 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*ft_new_fractal(t_vector2 r, t_vector2 i, t_app *app)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	ft_nullerr_exit(fractal, app);
	fractal->min = r;
	fractal->max = i;
	fractal->c = ft_new_vector2(0, 0);
	fractal->iter = 42;
	fractal->color_phase = 0.75;
	fractal->color_factor = 0.02;
	app->fractal = fractal;
	return (fractal);
}

void	ft_clean_fractal(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}
