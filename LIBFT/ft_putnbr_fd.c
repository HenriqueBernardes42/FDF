/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:57:24 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/21 04:42:33 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	create(size_t pow, size_t big_n, int fd, char signal)
{
	size_t	cp_n;
	size_t	cp_pow;

	cp_pow = pow;
	while (pow)
	{	
		cp_n = big_n / pow;
		if (signal == '-' && (pow == cp_pow))
			cp_n = signal;
		else
			cp_n = cp_n % 10 + 48;
		ft_putchar_fd(cp_n, fd);
		pow /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t		cp_n;
	size_t		pow;
	size_t		big_n;
	char		signal;

	pow = 1;
	signal = '+';
	big_n = (size_t) n;
	if (n < 0)
	{
		big_n = big_n * -1;
		pow = 10;
		signal = '-';
	}
	cp_n = big_n;
	while (cp_n / 10)
	{
		cp_n /= 10;
		pow *= 10;
	}
	create(pow, big_n, fd, signal);
}
