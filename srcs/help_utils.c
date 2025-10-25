/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:36:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/25 13:38:09 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help_input(void)
{
	ft_putstr_fd("┌────────────────────────────────────────┐\n", STDOUT_FILENO);
	ft_putstr_fd("| Fract-ol 42school                      |\n", STDOUT_FILENO);
	ft_putstr_fd("|                                        |\n", STDOUT_FILENO);
	ft_putstr_fd("| HELP --------------------------------- |\n", STDOUT_FILENO);
	ft_putstr_fd("| To execute fractals, use the commands  |\n", STDOUT_FILENO);
	ft_putstr_fd("| -------------------------------------- |\n", STDOUT_FILENO);
	ft_putstr_fd("| ./bin/fractol mandelbrot               |\n", STDOUT_FILENO);
	ft_putstr_fd("| ./bin/fractol julia <real> <imag>      |\n", STDOUT_FILENO);
	ft_putstr_fd("| ./bin/fractol burningship              |\n", STDOUT_FILENO);
	ft_putstr_fd("└────────────────────────────────────────┘\n", STDOUT_FILENO);
}

void	ft_help_julia(void)
{
	ft_putstr_fd("┌────────────────────────────────────────┐\n", STDOUT_FILENO);
	ft_putstr_fd("| Examples input Julia's fract-ol        |\n", STDOUT_FILENO);
	ft_putstr_fd("|                                        |\n", STDOUT_FILENO);
	ft_putstr_fd("| -------------------------------------- |\n", STDOUT_FILENO);
	ft_putstr_fd("| ./bin/fractol julia 0 0.8              |\n", STDOUT_FILENO);
	ft_putstr_fd("| ./bin/fractol julia -0.835 -0.2321     |\n", STDOUT_FILENO);
	ft_putstr_fd("| ./bin/fractol julia  0.285  0          |\n", STDOUT_FILENO);
	ft_putstr_fd("└────────────────────────────────────────┘\n", STDOUT_FILENO);
}
