/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:25:03 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 03:11:40 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_header.h"

t_head	*create_list(void)
{	
	t_head	*head;

	head = calloc(2, sizeof(t_head));
	head->bgn = NULL;
	head->end = NULL;
	return (head);
}

t_node	*create_node(int x, int y, int color)
{
	t_node	*node;

	node = malloc(1 * sizeof(t_node));
	node->x = x;
	node->y = y;
	node->c = color;
	node->next = NULL;
	return (node);
}

void	add_last_list(t_head *head, int x, int y, int color)
{
	t_node	*node;

	node = create_node(x, y, color);
	if (head->bgn == NULL )
	{
		head->bgn = node;
		head->end = node;
	}
	else
	{
		head->end->next = node;
		head->end = head->end->next;
	}
}

void	do_empty_node(t_head *head)
{
	t_node	*node;
	int		i;

	i = 0;
	while (head->bgn)
	{
		node = head->bgn;
		head->bgn = node->next;
		free(node);
		++i;
	}
	free(head);
}

int	size_list(t_head *head)
{
	int	i;

	i = 0;
	while (head->end != NULL)
	{
		++i;
		head->end = head->end->next;
	}
	head->end = head->bgn;
	return (i);
}
