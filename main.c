/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:59:50 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/06/03 11:10:47 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "fdf.h"
#include <stdlib.h>

int			mouse_in(int x, int y, void *param)
{
	param = 0;
	g_height = 0.003f * (g_win_size.y / 2 - y);
	g_angle = (-(g_win_size.x / 2 - x) * 6.28f);
	if (g_mode == 0)
		mlx_clear_window(g_mlx.main, g_mlx.window);
	draw_map();
	return (0);
}

int			exp_hook(void)
{
	mlx_clear_window(g_mlx.main, g_mlx.window);
	draw_map();
	return (0);
}

int			key_in(int key, void *param)
{
	param = 0;
	if (key == 53)
	{
		while (g_map.bounds.y > 0)
			free(g_map.arr[--(g_map.bounds.y)]);
		free(g_map.arr);
		exit(0);
	}
	if (key == 8)
	{
		mlx_clear_window(g_mlx.main, g_mlx.window);
		draw_map();
	}
	if (key == 49)
	{
		g_mode = (g_mode == 0) ? 1 : 0;
	}
	return (0);
}

int			error(char *str)
{
	ft_putstr(str);
	return (0);
}

int			main(int argc, char **argv)
{
	int c;

	if (argc != 2)
		return (error("Usage: ./fdf file"));
	g_angle = 0;
	g_max = 1;
	g_mode = 0;
	g_map.bounds.x = 0;
	g_map.bounds.y = 0;
	if ((c = allocate_map(argv[1])) <= 0)
		return (c == 0) ? error("malloc failed") : error("Invalid file");
	g_win_size.x = 2500;
	g_win_size.y = 1500;
	g_height = 1;
	g_mlx.get_point = get_point_iso;
	g_mlx.main = mlx_init();
	g_mlx.window = mlx_new_window(g_mlx.main,
	g_win_size.x, g_win_size.y, "fdf");
	set_map();
	draw_map();
	mlx_hook(g_mlx.window, 6, 0, mouse_in, (void *)0);
	mlx_expose_hook(g_mlx.window, exp_hook, (void *)0);
	mlx_key_hook(g_mlx.window, key_in, (void *)0);
	mlx_loop(g_mlx.main);
	return (0);
}
