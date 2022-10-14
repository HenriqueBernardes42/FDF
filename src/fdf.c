/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:08:26 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 20:39:34 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"func_header.h"

int	close_window(t_manage *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->i.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_keypress(int keysym, t_manage *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_image(data->mlx_ptr, data->i.mlx_img);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	render(t_manage *dt)
{
	char	*file;
	t_head	*head;

	if (dt->win_ptr == NULL)
		return (1);
	head = create_list();
	file = ft_strjoin("maps/", dt->map);
	if ((open(file, O_RDONLY)) == -1)
	{
		free(file);
		do_empty_node(head);
		close_window(dt);
		return (0);
	}
	start_wire(dt, file, 1, head);
	free(file);
	do_empty_node(head);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->i.mlx_img, 0, 0);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x > WIN_WID || y > WIN_HEI || x < 0 || y < 0)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	main(int argc, char *argv[])
{
	t_manage	dt;

	dt.mlx_ptr = mlx_init();
	if (dt.mlx_ptr == NULL)
		return (MLX_ERROR);
	dt.win_ptr = mlx_new_window(dt.mlx_ptr, WIN_WID, WIN_HEI, "my window");
	if (dt.win_ptr == NULL)
	{
		free(dt.win_ptr);
		return (MLX_ERROR);
	}
	dt.i.mlx_img = mlx_new_image(dt.mlx_ptr, WIN_WID, WIN_HEI);
	dt.i.addr = mlx_get_data_addr(dt.i.mlx_img, &dt.i.bpp,
			&dt.i.line_len, &dt.i.endian);
	dt.map = argc[argv - 1];
	mlx_loop_hook(dt.mlx_ptr, &render, &dt);
	mlx_hook(dt.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &dt);
	mlx_hook(dt.win_ptr, 17, 0, &close_window, &dt);
	mlx_loop(dt.mlx_ptr);
	return (0);
}
