/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:45:23 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/20 08:36:03 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE 0x01
# define FALSE 0x00

typedef char	t_bool;

t_bool	ft_isdigit(char c);
t_bool	ft_isspace(char c);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
double	ft_atof(char *str);

#endif
