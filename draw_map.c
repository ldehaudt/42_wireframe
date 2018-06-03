/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:23:24 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/07 01:23:27 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_right(t_pos c, t_pos start, t_pos end, t_pos colors)
{
	c.x += 1;
	g_mlx.get_point(&end, c);
	colors.y = get_color(g_map.arr[c.y][c.x].z);
	mlx_draw_line(start, end, colors);
	c.x -= 1;
}

void		draw_down(t_pos c, t_pos start, t_pos end, t_pos colors)
{
	c.y += 1;
	g_mlx.get_point(&end, c);
	colors.y = get_color(g_map.arr[c.y][c.x].z);
	mlx_draw_line(start, end, colors);
	c.y -= 1;
}

void		draw_map(void)
{
	t_pos c;
	t_pos start;
	t_pos end;
	t_pos colors;

	end.x = 0;
	c.y = 0;
	while (c.y < g_map.bounds.y)
	{
		c.x = 0;
		while (c.x < g_map.bounds.x)
		{
			g_mlx.get_point(&start, c);
			colors.x = get_color(g_map.arr[c.y][c.x].z);
			if (c.x < g_map.bounds.x - 1)
				draw_right(c, start, end, colors);
			if (c.y < g_map.bounds.y - 1)
				draw_down(c, start, end, colors);
			c.x++;
		}
		c.y++;
	}
}
