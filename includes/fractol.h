/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:47:59 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/17 13:39:33 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>

# define MANDELBROT_NAME "mandelbrot"
# define JULIA_NAME "julia"

// Utils =======================================================================
t_bool	ft_validate_input(char *input, char *target);

#endif
