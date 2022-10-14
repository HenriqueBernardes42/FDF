/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_wires.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:25:31 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 03:10:20 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_header.h"

t_next	set_value(int current, int prev)
{
	t_next	value;

	value.x = current;
	value.y = prev;
	return (value);
}

void	draw_line(t_manage *d, t_next n, t_head *h, char **splitted)
{
	t_next	trgt;
	t_next	value;
	int		size;
	int		i;
	int		color;

	i = 0;
	while (splitted[++i - 1])
	{
		color = h->bgn->c;
		size = def_size(col_len(splitted));
		n = s_line(&d->i, (t_crd){h->bgn->x, h->bgn->y, n.x, n.y, color});
		h->bgn->x = n.x;
		h->bgn->y = n.y;
		if (splitted[i] == NULL)
			break ;
		value = set_value(ft_atoi(splitted[i]), ft_atoi(splitted[i - 1]));
		trgt = s_target(value.x, value.y, n, size);
		h->bgn->c = s_color(splitted, i);
		color = h->bgn->c;
		n = s_line(&d->i, (t_crd){n.x, n.y, trgt.x, trgt.y, color});
		h->bgn = h->bgn->next;
	}
}

void	form_wire(t_next next, t_manage *d, t_head *h, int fd)
{
	char	**splitted;
	char	*line;
	int		prev;
	int		len;

	prev = next.prev;
	line = get_next_line(fd);
	len = size_list(h);
	while (line)
	{
		splitted = ft_split(line, ' ');
		if (len != col_len(splitted))
		{
			line = special_case(line, splitted, fd);
			continue ;
		}
		next = define_next(h, prev, splitted, next);
		prev = ft_atoi(splitted[0]);
		draw_line(d, next, h, splitted);
		h->bgn = h->end;
		free_gnl(line, splitted);
		line = get_next_line(fd);
	}
}

static void	draw_first_line(char **splt, t_next n, t_head *h, t_manage *d)
{
	t_next	trgt;
	int		i;
	int		size;

	i = 1;
	size = def_size(col_len(splt));
	while (splt[1 + i++])
	{
		trgt = s_target(ft_atoi(splt[i]), ft_atoi(splt[i - 1]), n, size);
		h->bgn->c = s_color(splt, i);
		n = s_line(&d->i, (t_crd){n.x, n.y, trgt.x, trgt.y, h->bgn->c});
		add_last_list(h, n.x, n.y, h->bgn->c);
	}
}

void	start_wire(t_manage *data, char *file, int size, t_head *h)
{
	t_next	next;
	int		fd;
	char	*line;
	char	**splitted;
	int		prev;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	splitted = ft_split(line, ' ');
	size = def_size(col_len(splitted));
	add_last_list(h, X, Y + size / 2, PINK);
	h->bgn->c = s_color(splitted, 0);
	prev = h->bgn->c;
	next = s_line(&data->i, (t_crd){X, Y + size / 2, X + size, Y + size, prev});
	add_last_list(h, next.x, next.y, h->bgn->c);
	prev = ft_atoi(splitted[0]);
	draw_first_line(splitted, next, h, data);
	free_gnl(line, splitted);
	h->end = h->bgn;
	form_wire((t_next){next.x, next.y, prev}, data, h, fd);
}
