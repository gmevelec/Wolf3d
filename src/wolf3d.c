/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 13:51:41 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 19:25:28 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/wolf3d.h"
#include "../inc/image.h"
#include "../inc/move.h"
#include "../inc/print.h"
#include "../inc/ft_init.h"

int		key_hook(int keycode, t_param *p)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65362)
		moveup(p);
	else if (keycode == 65364)
		movedown(p);
	else if (keycode == 65363)
		moveright(p);
	else if (keycode == 65361)
		moveleft(p);
	return (0);
}

int		expose_hook(t_param *p)
{
	mlx_put_image_to_window(p->mlx, p->win, p->img.img_ptr, 0, 0);
	ft_print_fps(p);
	return (0);
}

int		main(void)
{
	t_param		p;

	ft_init(&p);
	ft_draw_map(&p);
	mlx_hook(p.win, 2, 1, key_hook, &p);
	mlx_loop_hook(p.mlx, expose_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
