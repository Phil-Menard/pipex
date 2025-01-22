/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:14:38 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/10 11:53:52 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *result);
void	ft_putstr(char *str, int *result);
void	ft_putadd(void *p, int *result);
void	ft_putnum(int nb, int *result);
void	ft_put_unum(unsigned int nb, int *result);
void	ft_puthex(unsigned int x, int *result, char c);
size_t	len_unint(unsigned int n);

#endif