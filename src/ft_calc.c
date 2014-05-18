/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:13:15 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 18:56:04 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../inc/ft_calc.h"

float	get_k_on_x(t_param *p, t_coord v)
{
	int		x;
	float	k;
	float	kx;
	float	y;
	int		test;

	x = -1;
	k = 10000000;
	while (++x < MAP_X)
	{
		test = 0;
		if (v.x < 0)
			test = -1;
		kx = (x - p->pos.x) / v.x;
		y = p->pos.y + (kx * v.y);
		if (y >= 0 && kx >= 0 && y < MAP_Y &&
			p->lab[(int)x + test][(int)y] && kx < k)
			k = kx;
	}
	return (k);
}

float	get_k_on_y(t_param *p, t_coord v)
{
	int		y;
	float	k;
	float	ky;
	float	x;
	int		test;

	y = -1;
	k = 10000000;
	while (++y < MAP_Y)
	{
		test = 0;
		if (v.y < 0)
			test = -1;
		ky = (y - p->pos.y) / v.y;
		x = p->pos.x + (ky * v.x);
		if (ky >= 0 && x >= 0 && x < MAP_X &&
			p->lab[(int)x][(int)y + test] && ky < k)
			k = ky;
	}
	return (k);
}

void	ft_calc(t_param *p, t_coord *pos2, int x)
{
	pos2->y = (WIN_X / 2.0 - x) / WIN_X;
	pos2->x = 0.5 * cos(p->pos.a) - pos2->y * sin(p->pos.a) + p->pos.x;
	pos2->y = 0.5 * sin(p->pos.a) + pos2->y * cos(p->pos.a) + p->pos.y;
}
