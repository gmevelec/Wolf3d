/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 10:14:22 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 19:22:39 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "../inc/draw.h"
#include "../inc/ft_calc.h"
#include "../inc/image.h"

static void		ft_draw_wall(t_param *p, t_coord px, int x2, int y2)
{
	int		pix;
	int		pix2;

	pix = p->img.sizeline * px.y + px.x * (p->img.bpp / 8);
	pix2 = p->wall.sizeline * y2 + x2 * (p->wall.bpp / 8);
	p->img.data[pix] = p->wall.data[pix2];
	p->img.data[pix + 1] = p->wall.data[pix2 + 1];
	p->img.data[pix + 2] = p->wall.data[pix2 + 2];
}

static void		ft_draw_sky(t_param *p, int x, int y)
{
	int		pix;
	int		pix2;
	int		x2;
	int		y2;

	x2 = (p->sky.width / (2.0 * M_PI)) * -p->pos.a + x;
	y2 = (y / (WIN_Y / 2.0)) * p->sky.height;
	pix = p->img.sizeline * y + x * (p->img.bpp / 8);
	pix2 = p->sky.sizeline * y2 + x2 * (p->sky.bpp / 8);
	p->img.data[pix] = p->sky.data[pix2];
	p->img.data[pix + 1] = p->sky.data[pix2 + 1];
	p->img.data[pix + 2] = p->sky.data[pix2 + 2];
}

static void		ft_draw_map2(t_param *p, int size, int x, float percentx)
{
	int		y;
	float	skysize;
	t_coord	px;

	skysize = WIN_Y / 2.0 - size;
	y = -1;
	px.x = x;
	while (++y < WIN_Y)
	{
		px.y = y;
		if (y < skysize)
			ft_draw_sky(p, x, y);
		else if (y < (WIN_Y / 2.0 + size))
			ft_draw_wall(p, px, ((float)(percentx - (int)percentx))
							* p->wall.width, ((y - skysize) /
							(2.0 * size)) * p->wall.height);
		else
			ft_pixel_put_to_image(p, x, y, 0xAAAAAA);
	}
}

void			ft_draw_map(t_param *p)
{
	int			x;
	t_coord		pos2;
	t_coord		v;
	t_coord		k;
	int			size;

	x = -1;
	while (++x < WIN_X)
	{
		ft_calc(p, &pos2, x);
		v.x = pos2.x - p->pos.x;
		v.y = pos2.y - p->pos.y;
		k.x = get_k_on_x(p, v);
		k.y = get_k_on_y(p, v);
		if (k.x < k.y)
		{
			size = WIN_Y / (2.0 * k.x);
			ft_draw_map2(p, size, x, p->pos.y + k.x * v.y);
		}
		else
		{
			size = WIN_Y / (2.0 * k.y);
			ft_draw_map2(p, size, x, p->pos.x + k.y * v.x);
		}
	}
}
