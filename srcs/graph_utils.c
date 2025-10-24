/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:18:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/21 16:58:23 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_graph	*ft_new_graph(t_app *app)
{
	t_graph	*graph;
	int		*bpp;
	int		*size;
	int		*endian;

	if (!app)
		return (NULL);
	graph = malloc(sizeof(t_graph));
	ft_nullerr_exit(graph, app);
	graph->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, app->name);
	ft_nullerr_exit(graph->win, app);
	graph->img = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	ft_nullerr_exit(graph->img, app);
	bpp = &graph->bpp;
	size = &graph->size;
	endian = &graph->endian;
	graph->addr = mlx_get_data_addr(graph->img, bpp, size, endian);
	ft_nullerr_exit(graph->addr, app);
	return (graph);
}

void	ft_clean_graph(void *ptr, void *mlx)
{
	t_graph	*graph;

	if (!ptr || !mlx)
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		return ;
	}
	graph = (t_graph *)ptr;
	if (graph->img)
		mlx_destroy_image(mlx, graph->img);
	if (graph->win)
		mlx_destroy_window(mlx, graph->win);
	free(graph);
}
