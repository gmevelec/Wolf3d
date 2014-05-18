/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:11:47 by gmevelec          #+#    #+#             */
/*   Updated: 2014/01/13 19:11:54 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <mlx.h>
#include "../inc/print.h"

static char			*ft_put_in_tab(char *str, int sign, int c, int nb)
{
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(str) * (c + sign + 1));
	if (sign == 1)
	{
		str[i] = '-';
		i++;
		c++;
	}
	str[c] = '\0';
	while (i < c)
	{
		c--;
		str[c] = (nb % 10) + 48;
		nb /= 10;
	}
	return (str);
}

static char			*ft_treat_lim_neg(char *str)
{
	str = (char *)malloc(sizeof(str) * 12);
	str[0] = '-';
	str[1] = 2 + 48;
	str[2] = 1 + 48;
	str[3] = 4 + 48;
	str[4] = 7 + 48;
	str[5] = 4 + 48;
	str[6] = 8 + 48;
	str[7] = 3 + 48;
	str[8] = 6 + 48;
	str[9] = 4 + 48;
	str[10] = 8 + 48;
	str[11] = '\0';
	return (str);
}

static char			*ft_itoa(int n)
{
	int		sign;
	int		c;
	int		nb;
	char	*dst;

	sign = 0;
	c = 1;
	if (n == -2147483648)
		dst = ft_treat_lim_neg(dst);
	else
	{
		if (n < 0)
		{
			n *= -1;
			sign = 1;
		}
		nb = n;
		while (n > 9)
		{
			n /= 10;
			c++;
		}
		dst = ft_put_in_tab(dst, sign, c, nb);
	}
	return (dst);
}

void				ft_print_fps(t_param *p)
{
	static int	fps;
	static int	timestamp;
	static int	fps_r;

	if (timestamp != time(NULL))
	{
		timestamp = (int)time(NULL);
		fps_r = fps;
		fps = 0;
	}
	else
		fps++;
	mlx_string_put(p->mlx, p->win, WIN_X - 60, 20, 0x000000, "fps :");
	mlx_string_put(p->mlx, p->win, WIN_X - 20, 20, 0x000000, ft_itoa(fps_r));
}
