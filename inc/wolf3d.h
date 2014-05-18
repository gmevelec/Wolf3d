/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 13:58:35 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 19:03:48 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_X 1024
# define WIN_Y 768
# define MAP_X 12
# define MAP_Y 14

typedef struct	s_coord
{
	float		x;
	float		y;
	float		a;
}				t_coord;

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct	s_param
{
	void			*mlx;
	void			*win;
	int				lab[MAP_X][MAP_Y];
	t_coord			pos;
	t_img			img;
	t_img			wall;
	t_img			sky;
	t_img			floor;
}				t_param;

int		key_hook(int keycode, t_param *param);
int		expose_hook(t_param *param);
void	ft_draw_map(t_param *param);

#endif
