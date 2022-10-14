/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 06:06:48 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/10 06:07:23 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head_next;

	if (!lst)
		return ;
	while (*lst)
	{
		head_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = head_next;
	}
}
