/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:56:50 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/24 14:32:34 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_help_input();
	else if (argc == 2 && ft_input_validate(argv[1], MANDELBROT_NAME))
		ft_fractal_mandelbrot(argv);
	else if (argc == 4 && ft_input_validate(argv[1], JULIA_NAME))
		ft_fractal_julia(argv);
	else if (argc == 2 && ft_input_validate(argv[1], BURNINGSHIP_NAME))
		ft_fractal_burningship(argv);
	else
		ft_help_input();
	return (EXIT_SUCCESS);
}
