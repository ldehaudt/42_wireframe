/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:12:33 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/16 17:24:09 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_pos_float
{
	float		x;
	float		y;
}				t_pos_float;

typedef struct	s_vector
{
	int		x;
	int		y;
	int		z;
}				t_vector;

typedef struct	s_map
{
	t_vector	**arr;
	t_pos		bounds;
}				t_map;

typedef struct	s_lib_ptrs
{
	void	*main;
	void	*window;
	void	(*get_point) (t_pos *pos, t_pos c);
}				t_lib_ptrs;

float		g_max;
float		g_height;
t_map		g_map;
t_lib_ptrs	g_mlx;
t_pos		g_win_size;
float		g_angle;
int			g_mode;

int				make_gradient(int start, int end, float percent);
int				get_color(int height);
void			set_map(void);
int				allocate_map(char *file);
void			get_point_iso(t_pos *pos, t_pos c);
void			get_point_round(t_pos *pos, t_pos c);
void			get_point_cylinder(t_pos *pos, t_pos c);
void			draw_map(void);
void			mlx_draw_line(t_pos start, t_pos end, t_pos colors);
int				abs(int n);
int				signof(int n);

#endif
