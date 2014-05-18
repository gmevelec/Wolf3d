/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 10:05:23 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 18:11:07 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "../inc/move.h"
#include "../inc/draw.h"

void		moveup(t_param *p)
{
	check_front_wall(p);
	ft_draw_map(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img_ptr, 0, 0);
}

void		movedown(t_param *p)
{
	check_behind_wall(p);
	ft_draw_map(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img_ptr, 0, 0);
}

void		moveright(t_param *p)
{
	p->pos.a -= 0.2;
	if (p->pos.a < 0.2)
		p->pos.a = 2 * M_PI;
	ft_draw_map(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img_ptr, 0, 0);
}

void		moveleft(t_param *p)
{
	p->pos.a += 0.2;
	if (p->pos.a > (2 * M_PI))
		p->pos.a = 0.2;
	ft_draw_map(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img_ptr, 0, 0);
}
