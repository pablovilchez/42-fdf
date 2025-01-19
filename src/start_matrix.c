/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:18:29 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/27 23:35:10 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_isometric(t_vertex **matrix, int *rows)
{
	int		x;
	int		y;
	int		lenght;

	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			matrix[y][x].dest.x = (1.0 / sqrt(2)) * matrix[y][x].start.x;
			matrix[y][x].dest.x -= (1.0 / sqrt(2)) * matrix[y][x].start.y;
			matrix[y][x].dest.y = (1.0 / sqrt(6)) * matrix[y][x].start.x;
			matrix[y][x].dest.y += (1.0 / sqrt(6)) * matrix[y][x].start.y;
			matrix[y][x].dest.y -= matrix[y][x].high * 1;
			x++;
		}
		y++;
	}
}

void	line_len(t_vertex *matrix_line, int total_x)
{
	int		x;

	x = 0;
	while (x < total_x)
	{
		matrix_line[x].len = total_x;
		x++;
	}
}

void	start_matrix(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	t_axis	start;
	int		margin;
	int		x;
	int		y;
	int		lenght;

	start.x = 0;
	start.y = 0;
	margin = 10;
	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			matrix[y][x].start.x = start.x + margin * x;
			matrix[y][x].start.y = start.y + margin * y;
			x++;
		}
		y++;
	}
	make_isometric(matrix, rows);
	adjust_values(matrix, rows, mmsizes);
}
