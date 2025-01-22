/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:44:01 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/13 15:56:26 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	x;
	char		c;

	x = (long int) n;
	if (x < 0)
	{
		write(fd, "-", 1);
		x *= -1;
	}
	if (x > 9)
		ft_putnbr_fd(x / 10, fd);
	c = (x % 10) + '0';
	write(fd, &c, 1);
}

/*
int	main(void)
{
	ft_putnbr_fd(5*20, 1);
	return (0);
}
*/