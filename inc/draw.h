/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 10:16:46 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/15 18:04:12 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "wolf3d.h"

void	ft_draw_map(t_param *p);
void	check_front_wall(t_param *p);
void	check_behind_wall(t_param *p);

#endif
