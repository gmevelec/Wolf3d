/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:53:42 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 19:17:12 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/ft_init.h"

static void		ft_init_lab(t_param *p)
{
	int		i;
	int		j;
	int		lab[MAP_X][MAP_Y] =
	{
		{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
		{6, 0, 2, 2, 2, 2, 2, 0, 0, 3, 0, 3, 0, 6},
		{6, 0, 2, 0, 0, 0, 2, 0, 0, 3, 0, 3, 0, 6},
		{6, 0, 2, 2, 1, 2, 2, 0, 0, 3, 0, 3, 0, 6},
		{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{6, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{6, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{6, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{6, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{6, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}
	};

	i = -1;
	while (++i < MAP_X)
	{
		j = -1;
		while (++j < MAP_Y)
			p->lab[i][j] = lab[i][j];
	}
}

void			ft_init(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, "WOLF3D");
	p->img.img_ptr = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->img.data = mlx_get_data_addr(p->img.img_ptr, &(p->img.bpp),
									&(p->img.sizeline), &(p->img.endian));
	p->pos.x = 1.5;
	p->pos.y = 1.5;
	p->pos.a = 0;
	p->sky.img_ptr = mlx_xpm_file_to_image(p->mlx, "img/skybox3.xpm",
										&p->sky.width, &p->sky.height);
	p->sky.data = mlx_get_data_addr(p->sky.img_ptr, &(p->sky.bpp),
									&(p->sky.sizeline), &(p->sky.endian));
	mlx_put_image_to_window(p->mlx, p->win, p->sky.img_ptr, 0, 0);
	p->wall.img_ptr = mlx_xpm_file_to_image(p->mlx, "img/wall.xpm",
										&p->wall.width, &p->wall.height);
	p->wall.data = mlx_get_data_addr(p->wall.img_ptr, &(p->wall.bpp),
									&(p->wall.sizeline), &(p->wall.endian));
	p->floor.img_ptr = mlx_xpm_file_to_image(p->mlx, "img/grass.xpm",
											&p->floor.width, &p->floor.height);
	p->floor.data = mlx_get_data_addr(p->floor.img_ptr, &(p->floor.bpp),
									&(p->floor.sizeline), &(p->floor.endian));
	ft_init_lab(p);
}
