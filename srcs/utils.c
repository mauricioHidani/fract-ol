/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:19:52 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/25 14:26:47 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	ft_input_validate(char *input, char *target)
{
	size_t	target_length;
	size_t	input_length;
	t_bool	has_same_length;

	if (!input || !target)
		return (FALSE);
	target_length = ft_strlen(target);
	input_length = ft_strlen(input);
	has_same_length = target_length == input_length;
	if (ft_strncmp(input, target, target_length) == 0 && has_same_length)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_validade_double(char *nbr)
{
	int	i;
	int	count_dot;

	i = 0;
	count_dot = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] && (ft_isdigit(nbr[i]) || nbr[i] == '.' || nbr[i] == ','))
	{
		if (nbr[i] == '.' || nbr[i] == ',')
			count_dot++;
		i++;
	}
	if (nbr[i] || count_dot > 1)
		return (FALSE);
	return (TRUE);
}

t_vector2	ft_input_julia_complex(char *c1, char *c2, t_app *app)
{
	t_vector2	c;

	if (!c1 || !c2 || !ft_validade_double(c1) || !ft_validade_double(c2))
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		ft_help_julia();
		ft_clean_app(app);
		exit(EXIT_FAILURE);
	}
	c.x = ft_atof(c1);
	c.y = ft_atof(c2);
	return (c);
}

void	ft_nullerr_exit(void *ptr, void *release)
{
	if (!ptr)
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		ft_clean_app(release);
		exit(EXIT_FAILURE);
	}
}

int	ft_close_win(void *param)
{
	mlx_loop_end(((t_app *)param)->mlx);
	ft_clean_app(param);
	exit(EXIT_FAILURE);
}
