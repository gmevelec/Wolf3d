/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:44:25 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/14 17:50:38 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../inc/ft_check.h"

void	check_front_wall(t_param *p)
{
	float	x;
	float	y;

	x = p->pos.x + 0.1 * cos(p->pos.a);
	y = p->pos.y + 0.1 * sin(p->pos.a);
	if ((p->lab[(int)x][(int)y]) > 1)
	{
		if (p->lab[(int)x][(int)p->pos.y] < 2)
			p->pos.x = x;
		else if (p->lab[(int)p->pos.x][(int)y] < 2)
			p->pos.y = y;
	}
	else
	{
		p->pos.x = x;
		p->pos.y = y;
	}
}

void	check_behind_wall(t_param *p)
{
	float	x;
	float	y;

	x = p->pos.x - 0.1 * cos(p->pos.a);
	y = p->pos.y - 0.1 * sin(p->pos.a);
	if ((p->lab[(int)x][(int)y]) > 1)
	{
		if (p->lab[(int)x][(int)p->pos.y] < 2)
			p->pos.x = x;
		else if (p->lab[(int)p->pos.x][(int)y] < 2)
			p->pos.y = y;
	}
	else
	{
		p->pos.x = x;
		p->pos.y = y;
	}
}
