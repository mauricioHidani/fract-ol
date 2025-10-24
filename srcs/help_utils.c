/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:36:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/24 00:03:51 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// todo: issue
void	ft_help_input(void)
{
	ft_putstr_fd("Help start fractol application\n", STDOUT_FILENO);
	ft_putstr_fd("Examples of entries in the application\n", STDOUT_FILENO);
	ft_putstr_fd("\tMandelbrot: ./bin/fractol mandelbrot\n", STDOUT_FILENO);
	ft_putstr_fd("\tJulia: ./bin/fractol julia -0.835 -0.2321\n", STDOUT_FILENO);
	ft_putstr_fd("\tJulia: ./bin/fractol julia 0.285 0.0\n", STDOUT_FILENO);
	ft_putstr_fd("\tJulia: ./bin/fractol julia 0.285 0\n", STDOUT_FILENO);
	ft_putstr_fd("\tBurningship: ./fractol burningship\n", STDOUT_FILENO);
}

// todo: issue
void	ft_help_julia(void)
{
}
