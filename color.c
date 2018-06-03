/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:24:20 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/07 13:53:52 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_color(int height)
{
	if (height <= 1 && height >= -1)
	{
		return (16777215);
	}
	else if (height > 5)
	{
		return (12062786);
	}
	else if (height > 3)
	{
		return (15106670);
	}
	else if (height > 1)
	{
		return (16111721);
	}
	else if (height >= -3)
	{
		return (10475769);
	}
	else
	{
		return (5605339);
	}
}

t_vector	get_rgb(int col)
{
	t_vector rgb;

	rgb.z = col % 256;
	rgb.y = ((col - rgb.z) % 65536) / 256;
	rgb.x = (col - rgb.y - rgb.z) / 65536;
	return (rgb);
}

int			make_gradient(int start, int end, float percent)
{
	t_vector rgb_start;
	t_vector rgb_end;

	rgb_start = get_rgb(start);
	rgb_end = get_rgb(end);
	return ((rgb_start.x + (int)((rgb_end.x - rgb_start.x) * percent)) * 65536
	+ (rgb_start.y + (int)((rgb_end.y - rgb_start.y) * percent)) * 256
	+ rgb_start.z + (rgb_end.z - rgb_start.z) * percent);
}
