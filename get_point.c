/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:11:41 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/07 01:23:45 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		get_point_iso(t_pos *pos, t_pos c)
{
	int			ratio;
	t_pos_float	sin_cos;
	t_pos_float	start;
	float		x_point;
	float		y_point;

	start.x = g_map.arr[c.y][c.x].x - g_map.bounds.x / 2;
	start.y = g_map.arr[c.y][c.x].y - g_map.bounds.y / 2;
	sin_cos.x = sin(g_angle);
	sin_cos.y = cos(g_angle);
	x_point = start.x * sin_cos.y - start.y * sin_cos.x;
	y_point = start.x * sin_cos.x + start.y * sin_cos.y;
	ratio = (g_win_size.x / g_map.bounds.x > g_win_size.y / g_map.bounds.y) ?
	g_win_size.y / g_map.bounds.y / 1.5f : g_win_size.x / g_map.bounds.x / 1.5f;
	(*pos).x = g_win_size.x / 2 + (x_point) * ratio + (y_point) * ratio;
	(*pos).y = g_win_size.y / 2 - (x_point) * ratio / 2 + (y_point)
		* ratio / 2 - g_height * (g_map.arr[c.y][c.x].z / g_max) * 200;
}

void		get_point_round(t_pos *pos, t_pos c)
{
	int			ratio;
	t_pos_float	sin_cos;
	t_pos_float	start;
	float		x_point;
	float		y_point;

	start.x = g_map.arr[c.y][c.x].x - g_map.bounds.x / 2;
	start.y = g_map.arr[c.y][c.x].y;
	sin_cos.x = sin(g_angle);
	sin_cos.y = cos(g_angle);
	x_point = start.x * sin_cos.y - start.y * sin_cos.x;
	y_point = start.x * sin_cos.x + start.y * sin_cos.y;
	ratio = (g_win_size.x / g_map.bounds.x > g_win_size.y / g_map.bounds.y)
		? g_win_size.y / g_map.bounds.y / 4 : g_win_size.x / g_map.bounds.x / 4;
	(*pos).x = g_win_size.x / 2 + (g_map.arr[c.y][c.x].x - g_map.bounds.x / 2)
		* (30 + (y_point * ratio / 6));
	(*pos).y = g_win_size.y / 10 + (y_point) * ratio / 1.5f * (1 + 0.2f
		* y_point) - g_height * (g_map.arr[c.y][c.x].z / g_max) * 200;
}

void		get_point_cylinder(t_pos *pos, t_pos c)
{
	int ratio;

	ratio = (g_win_size.x / g_map.bounds.x > g_win_size.y / g_map.bounds.y)
		? g_win_size.y / g_map.bounds.y / 4 : g_win_size.x / g_map.bounds.x / 4;
	(*pos).x = g_win_size.x / 2 + (g_map.arr[c.y][c.x].x - g_map.bounds.x / 2)
		* (30 + ((g_map.arr[c.y][c.x].y) * ratio / 6));
	(*pos).y = g_win_size.y / 4 + (g_map.arr[c.y][c.x].y) * ratio / 1.5f
		* (1 + 0.2f * (g_map.arr[c.y][c.x].y - g_map.bounds.y / 2))
		- (g_map.arr[c.y][c.x].z / g_max) * 200;
}
