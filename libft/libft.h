/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:45:23 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/17 13:04:31 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

# define TRUE 0x01
# define FALSE 0x00

typedef char	t_bool;

t_bool	ft_isdigit(char c);
t_bool	ft_isspace(char c);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *str1, char *str2, size_t n);
double	ft_atof(char *str);

#endif
