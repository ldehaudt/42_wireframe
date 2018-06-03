/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:23:07 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/07 01:23:10 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "minilibx/mlx.h"

void		mlx_draw_rl(t_pos start, t_pos dif, t_pos colors)
{
	float	count;
	float	ratio;
	int		down;

	down = 1;
	count = 0;
	ratio = (float)dif.x / (float)dif.y;
	while (count < abs(dif.x))
	{
		if (count / down > fabs(ratio))
			down++;
		mlx_pixel_put(g_mlx.main, g_mlx.window, start.x +
			(count * signof(dif.x)),
		start.y + (down * signof(dif.y)), make_gradient(colors.x, colors.y,
		count / abs(dif.x)));
		count++;
	}
}

void		mlx_draw_ud(t_pos start, t_pos dif, t_pos colors)
{
	float	count;
	float	ratio;
	int		side;

	side = 1;
	count = 0;
	ratio = (float)dif.y / (float)dif.x;
	while (count < abs(dif.y))
	{
		if (count / side > fabs(ratio))
			side++;
		mlx_pixel_put(g_mlx.main, g_mlx.window, start.x +
		(side * signof(dif.x)),
		start.y + (count * signof(dif.y)),
		make_gradient(colors.x, colors.y, count / abs(dif.y)));
		count++;
	}
}

void		mlx_draw_line(t_pos start, t_pos end, t_pos colors)
{
	t_pos dif;

	dif.x = end.x - start.x;
	dif.y = end.y - start.y;
	if (abs(dif.x) >= abs(dif.y))
		mlx_draw_rl(start, dif, colors);
	else
		mlx_draw_ud(start, dif, colors);
}
