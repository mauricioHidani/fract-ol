/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:25:55 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/25 13:05:07 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define MANDELBROT_NAME "mandelbrot"
# define JULIA_NAME "julia"
# define BURNINGSHIP_NAME "burningship"

# define WIDTH 800
# define HEIGHT 600
# define SHIFT_FACTOR 0.12
# define ZOOM_IN_FACTOR 0.8
# define ZOOM_OUT_FACTOR 1.25
# define RESOLUTION_FACTOR 1.2
# define COLOR_FACTOR 0.22
# define ERROR_MSG "Error\n"

typedef struct s_vector2
{
	double	x;
	double	y;
}			t_vector2;

typedef struct s_graph
{
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
}			t_graph;

typedef struct s_fractal
{
	t_vector2	min;
	t_vector2	max;
	t_vector2	z;
	t_vector2	c;
	int			iter;
	double		color_phase;
	double		color_factor;
}				t_fractal;

typedef struct s_app
{
	char		*name;
	void		*mlx;
	t_graph		*graph;
	t_fractal	*fractal;
}				t_app;

// Handler Fractals ------------------------------------------------------------
void		ft_fractal_mandelbrot(char **argv);
void		ft_fractal_julia(char **argv);
void		ft_fractal_burningship(char **argv);

// Fractal Type ----------------------------------------------------------------
t_fractal	*ft_new_fractal(t_vector2 r, t_vector2 i, t_app *a);
void		ft_clean_fractal(void *ptr);

// App Utils -------------------------------------------------------------------
t_app		*ft_new_app(char **argv);
void		ft_clean_app(void *ptr);

// Graph Utils -----------------------------------------------------------------
t_graph		*ft_new_graph(t_app *app);
void		ft_clean_graph(void *ptr, void *mlx);

// Vector2D --------------------------------------------------------------------
t_vector2	ft_new_vector2(double x, double y);

// Render ----------------------------------------------------------------------
void		ft_render(t_app *app, void (*f)(t_vector2, t_graph *, t_fractal *));
void		ft_put_pixel(t_vector2 v2, int color, t_graph *graph);
int			ft_build_color(double i, t_vector2 z, t_fractal *fractal);

// Handle Keyboard And Mouse ---------------------------------------------------
void		ft_handle_keyboard(int keycode, void *param);
t_bool		ft_handle_mouse(int keycode, t_vector2 mouse_pos, void *param);

// Help Utils ------------------------------------------------------------------
void		ft_help_input(void);
void		ft_help_julia(void);

// Utils -----------------------------------------------------------------------
t_bool		ft_input_validate(char *input, char *target);
t_bool		ft_validade_double(char *nbr);
t_vector2	ft_input_julia_complex(char *c1, char *c2, t_app *app);
void		ft_nullerr_exit(void *ptr, void *release);
int			ft_close_win(void *param);

#endif
