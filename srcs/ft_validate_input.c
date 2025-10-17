/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:33:48 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/17 13:39:33 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	ft_validate_input(char *input, char *target)
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
