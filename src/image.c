/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 15:33:53 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 19:10:08 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/image.h"
#include "../inc/wolf3d.h"

void	ft_pixel_put_to_image(t_param *param, int x, int y
							  , unsigned int img_color)
{
	int				pix;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	img_color = mlx_get_color_value(param->mlx, img_color);
	r = (img_color & 0xFF0000) >> 16;
	g = (img_color & 0xFF00) >> 8;
	b = (img_color & 0xFF) >> 0;
	pix = param->img.sizeline * y + x * (param->img.bpp / 8);
	param->img.data[pix] = b;
	param->img.data[pix + 1] = g;
	param->img.data[pix + 2] = r;
}
