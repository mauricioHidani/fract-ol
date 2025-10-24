/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:12:00 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/24 14:48:13 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_app	*ft_new_app(char **argv)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	ft_nullerr_exit(app, NULL);
	app->name = argv[1];
	ft_nullerr_exit(app->name, app);
	app->mlx = mlx_init();
	ft_nullerr_exit(app->mlx, app);
	app->graph = ft_new_graph(app);
	ft_nullerr_exit(app->graph, app);
	return (app);
}

void	ft_clean_app(void *ptr)
{
	t_app	*app;

	if (!ptr)
		return ;
	app = (t_app *)ptr;
	if (app->graph)
		ft_clean_graph(app->graph, app->mlx);
	if (app->fractal)
		ft_clean_fractal(app->fractal);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	free(app);
}
