/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:37:25 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/25 01:12:45 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*csrc;

	dst = (char *)dest;
	csrc = (char *)src;
	if (src >= dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n)
		{
			dst[n - 1] = csrc[n - 1];
			--n;
		}
	}
	return (dst);
}
