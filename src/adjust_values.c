/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:33:19 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/28 23:14:02 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reduce_size(t_vertex **matrix, int *rows, int factor)
{
	int	x;
	int	y;
	int	lenght;

	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			matrix[y][x].dest.x *= 100;
			matrix[y][x].dest.x /= factor;
			matrix[y][x].dest.y *= 100;
			matrix[y][x].dest.y /= factor;
			matrix[y][x].high *= 100;
			matrix[y][x].high /= factor;
			x++;
		}
		y++;
	}
}

void	calc_img_size(t_mmsizes *mmsizes, t_vertex **matrix, int *rows)
{
	if (mmsizes->max_x > 1400 || mmsizes->max_y > 800)
	{
		if (mmsizes->max_x / 1400 > mmsizes->max_y / 800)
			reduce_size(matrix, rows, mmsizes->max_x * 100 / 1400);
		else
			reduce_size(matrix, rows, mmsizes->max_y * 100 / 800);
	}
	else
	{
		if (mmsizes->max_x / 1400 > mmsizes->max_y / 800)
			reduce_size(matrix, rows, mmsizes->max_x * 100 / 600);
		else
			reduce_size(matrix, rows, mmsizes->max_y * 100 / 250);
	}
}

void	calc_maxims(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	int	x;
	int	y;
	int	lenght;

	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			if (matrix[y][x].dest.x > mmsizes->max_x)
				mmsizes->max_x = matrix[y][x].dest.x;
			if (matrix[y][x].dest.y > mmsizes->max_y)
				mmsizes->max_y = matrix[y][x].dest.y;
			x++;
		}
		y++;
	}
}

void	calc_minims(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	int	x;
	int	y;
	int	lenght;

	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			if (matrix[y][x].dest.x < mmsizes->min_x)
				mmsizes->min_x = matrix[y][x].dest.x;
			if (matrix[y][x].dest.y < mmsizes->min_y)
				mmsizes->min_y = matrix[y][x].dest.y;
			x++;
		}
		y++;
	}
	if (mmsizes->min_x < 0)
		mmsizes->min_x *= -1;
	if (mmsizes->min_y < 0)
		mmsizes->min_y *= -1;
}

void	adjust_values(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	int	x;
	int	y;
	int	lenght;

	mmsizes->min_x = 0;
	mmsizes->min_y = 0;
	calc_minims(matrix, rows, mmsizes);
	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			matrix[y][x].dest.x += mmsizes->min_x;
			matrix[y][x].dest.y += mmsizes->min_y;
			x++;
		}
		y++;
	}
	calc_maxims(matrix, rows, mmsizes);
}
