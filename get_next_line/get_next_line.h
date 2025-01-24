/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:58:44 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/24 11:33:22 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlenline(const char *s);
char	*get_next_line(int fd);
int		ft_strchrline(char *src, int c);
char	*ft_putstrline(char *src, char *dest, int i);
char	*ft_putline(char *src, char *dest);
char	*ft_realloc(char *str, char *buffer);

#endif
