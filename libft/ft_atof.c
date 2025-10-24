/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:36:21 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/23 20:57:10 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	ft_isfrac(char c);
static void		ft_skip_spaces(char **pvt);
static void		ft_skip_set_sign(char **pvt, int *sign);
static void		ft_set_digit_in_nbr(char cdgt, int *frac_part, double *nbr);

double	ft_atof(char *str)
{
	double	nbr;
	char	*pvt;
	int		sign;
	int		frac_part;

	if (!str)
		return (0);
	pvt = str;
	ft_skip_spaces(&pvt);
	ft_skip_set_sign(&pvt, &sign);
	nbr = 0;
	frac_part = 0;
	while (*pvt != 0)
	{
		if (frac_part == 0 && ft_isfrac(*pvt))
			frac_part = 10;
		else if (frac_part > 0 && ft_isfrac(*pvt))
			break ;
		else if (ft_isdigit(*pvt))
			ft_set_digit_in_nbr(*pvt, &frac_part, &nbr);
		pvt++;
	}
	return (nbr * sign);
}

static t_bool	ft_isfrac(char c)
{
	if (c == '.' || c == ',')
		return (TRUE);
	return (FALSE);
}

static void	ft_skip_spaces(char **pvt)
{
	while (**pvt != 0 && ft_isspace(**pvt))
		(*pvt)++;
}

static void	ft_skip_set_sign(char **pvt, int *sign)
{
	*sign = 1;
	if (**pvt == '-' || **pvt == '+')
	{
		if (**pvt == '-')
			*sign = -1;
		(*pvt)++;
	}
}

static void	ft_set_digit_in_nbr(char cdgt, int *frac_part, double *nbr)
{
	int	digit;

	digit = cdgt - 48;
	if (*frac_part == 0)
		*nbr += *nbr * 10 + (double)digit;
	else if (*frac_part > 0)
	{
		*nbr += (double)digit / *frac_part;
		*frac_part *= 10;
	}
}
