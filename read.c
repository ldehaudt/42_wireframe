/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:07:31 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/16 17:31:11 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void		set_map(void)
{
	t_pos c;

	c.y = 0;
	while (c.y < g_map.bounds.y)
	{
		c.x = 0;
		while (c.x < g_map.bounds.x)
		{
			g_map.arr[c.y][c.x].x = c.x;
			g_map.arr[c.y][c.x].y = c.y;
			c.x++;
		}
		c.y++;
	}
}

void		alloc_cont(char **nums, int *count, int cur)
{
	g_map.arr[cur][*count].z = ft_atoi(nums[*count]);
	if (abs(g_map.arr[cur][*count].z) > g_max)
		g_max = abs(g_map.arr[cur][*count].z);
	free(nums[*count]);
	(*count)++;
}

int			recurse_alloc(int fd)
{
	char	*line;
	char	**nums;
	int		cur;
	int		count;
	int		ret;

	if (get_next_line(fd, &line) && (count = 0) == 0)
	{
		nums = ft_strsplit(line, ' ');
		free(line);
		cur = g_map.bounds.y;
		g_map.bounds.y++;
		ret = recurse_alloc(fd);
		g_map.bounds.x = 0;
		while (nums[g_map.bounds.x] != NULL)
			g_map.bounds.x++;
		if (!(g_map.arr[cur] = malloc(sizeof(t_vector) * g_map.bounds.x)))
			return (0);
		while (nums[count] != NULL)
			alloc_cont(nums, &count, cur);
		free(nums);
		return (ret);
	}
	return (g_map.arr = malloc(g_map.bounds.y * sizeof(t_vector *))) ? 1 : 0;
}

int			allocate_map(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (read(fd, NULL, 0))
		return (-1);
	return (recurse_alloc(fd));
}
