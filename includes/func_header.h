/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:39:02 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 06:58:23 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_HEADER_H
# define FUNC_HEADER_H

# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"

# define WIN_WID	1500
# define WIN_HEI	1300
# define X	10
# define Y	800
# define PINK	0XFF00FF
# define BUFFER_SIZE	1
# define MLX_ERROR 1
# define POSITIVE 1
# define NEGATIVE 0

typedef struct s_coord
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}t_crd;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_manage
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	i;
	char	*map;
}t_manage;

typedef struct s_next
{
	int	x;
	int	y;
	int	prev;
}t_next;

typedef struct s_dw_line
{
	int	decision_x;
	int	decision_y;
	int	fork;
	int	p;
	int	validate_negative;
}t_dw_line;

//linked list
typedef struct s_node
{
	int				x;
	int				y;
	int				c;
	struct s_node	*next;
}t_node;

typedef struct s_head
{
	t_node	*bgn;
	t_node	*end;
}t_head;

t_next	set_value(int current, int prev);
void	form_wire(t_next next, t_manage *data, t_head *head, int fd);
void	start_wire(t_manage *data, char *file, int i, t_head *h);
t_head	*create_list(void);
t_node	*create_node(int x, int y, int color);
void	add_last_list(t_head *head, int x, int y, int color);
void	do_empty_node(t_head *head);
int		handle_keypress(int keysym, t_manage *data);
int		render(t_manage *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int		main(int argc, char *argv[]);
void	img_pix_put(t_img *img, int x, int y, int color);
t_next	line_down_45(t_dw_line line, t_crd pos, t_img *img, t_next r_value);
t_next	line_up_45(t_dw_line line, t_crd pos, t_img *img, t_next r_value);
t_next	s_line(t_img *img, t_crd pos);
int		col_len(char **line_separated);
t_next	s_target(int current, int prev, t_next next, int size);
int		def_size(int n_lines);
int		s_color(char **line_separated, int i);
int		hex_to_int(char *hexadecimal);
void	free_split(char **splt);
void	free_gnl(char *line, char **splited );
void	free_split(char **splt);
int		size_list(t_head *head);
char	*special_case(char *line, char **splitted, int fd);
t_next	define_next(t_head *h, int prev, char **splitted, t_next next);

#endif