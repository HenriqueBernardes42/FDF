/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:09:56 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 02:51:16 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_header.h"

t_next	define_next(t_head *h, int prev, char **splitted, t_next next)
{
	int	size;

	size = def_size(col_len(splitted));
	next.y = h->bgn->y - size + (prev - ft_atoi(splitted[0]));
	next.x = h->bgn->x + size;
	return (next);
}

t_next	line_down_45(t_dw_line line, t_crd pos, t_img *img, t_next r_value)
{
	int	y;

	y = 0;
	line.p = (2 * line.decision_y) - (2 * line.decision_x);
	while ((pos.x + 1) <= r_value.x)
	{
		if (line.p <= 0)
		{
			++pos.x;
			line.p = line.p + (2 * line.decision_y);
		}
		else
		{
			++y;
			++pos.x;
			line.p = line.p + (2 * line.decision_y) - (2 * line.decision_x);
		}
		if (line.validate_negative == POSITIVE)
			img_pix_put(img, pos.x, (WIN_HEI - pos.y) - y, pos.color);
		else
			img_pix_put(img, pos.x, (WIN_HEI - pos.y) + y, pos.color);
	}
	return (r_value);
}

t_next	line_up_45(t_dw_line line, t_crd pos, t_img *img, t_next r_value)
{
	int	y;

	y = 0;
	line.p = (2 * line.decision_x) - (2 * line.decision_y);
	while ((pos.x + 1) <= r_value.x)
	{
		if (line.p > 0)
		{
			++y;
			++pos.x;
			line.p = line.p + (2 * line.decision_x) - (2 * line.decision_y);
		}
		else
		{
			++y;
			line.p = line.p + (2 * line.decision_x);
		}
		if (line.validate_negative == POSITIVE)
			img_pix_put(img, pos.x, (WIN_HEI - pos.y) - y, pos.color);
		else
			img_pix_put(img, pos.x, (WIN_HEI - pos.y) + y, pos.color);
	}
	return (r_value);
}

t_next	s_line(t_img *img, t_crd pos)
{
	t_dw_line		line;
	t_next			next;
	t_next			r_value;

	r_value.x = pos.width;
	r_value.y = pos.height;
	line.decision_x = pos.width - pos.x;
	line.decision_y = pos.height - pos.y;
	img_pix_put(img, pos.width, WIN_HEI - pos.height, pos.color);
	line.validate_negative = POSITIVE;
	if (line.decision_y < 0)
	{
		line.decision_y = line.decision_y * -1;
		line.validate_negative = NEGATIVE;
	}
	line.fork = line.decision_y / line.decision_x;
	if (line.fork >= 1)
		next = line_up_45(line, pos, img, r_value);
	else
		next = line_down_45(line, pos, img, r_value);
	return (next);
}
