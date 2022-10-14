/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 06:04:22 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/10 06:35:02 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	char	*new_content;
	t_list	*new;
	t_list	*lst_next;
	t_list	*new_next;
	t_list	**head;

	new_content = f(lst->content);
	new = ft_lstnew(new_content);
	lst_next = lst->next;
	new_next = new->next;
	head = &new;
	while (lst_next)
	{
		new_content = f(lst_next->content);
		new_next = ft_lstnew(new_content);
		if (!new_next)
		{
			ft_lstclear(&new_next, del);
			return (NULL);
		}
		ft_lstadd_back(head, new_next);
		lst_next = lst_next->next;
		new_next = new_next->next;
	}
	return (new);
}
