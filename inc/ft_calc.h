/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:22:01 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/14 18:43:11 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CALC_H
# define FT_CALC_H

# include "wolf3d.h"
# include "draw.h"

float	get_k_on_x(t_param *p, t_coord v);
float	get_k_on_y(t_param *p, t_coord v);
void	ft_calc(t_param *p, t_coord *pos2, int x);

#endif
