/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:07:50 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/28 21:31:03 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	paint_line(t_vertex *a, t_vertex *b, mlx_image_t *img, t_diff diff)
{
	int			current_x;
	int			current_y;
	int			err2;
	uint32_t	c;

	current_x = a->dest.x;
	current_y = a->dest.y;
	c = color(count_pix(a, b), a->color, b->color, 0);
	while (current_x != b->dest.x || current_y != b->dest.y)
	{
		mlx_put_pixel(img, current_x, current_y, c);
		err2 = 2 * diff.err;
		if (err2 > -diff.dy)
		{
			diff.err -= diff.dy;
			current_x += diff.sx;
		}
		if (err2 < diff.dx)
		{
			diff.err += diff.dx;
			current_y += diff.sy;
		}
		c = color(count_pix(a, b), a->color, b->color, 1);
	}
	mlx_put_pixel(img, current_x, current_y, c);
}

void	new_line(t_vertex *ver_a, t_vertex *ver_b, mlx_image_t *image)
{
	t_diff	diff;

	diff.dx = abs(ver_b->dest.x - ver_a->dest.x);
	diff.dy = abs(ver_b->dest.y - ver_a->dest.y);
	if (ver_a->dest.x < ver_b->dest.x)
		diff.sx = 1;
	else
		diff.sx = -1;
	if (ver_a->dest.y < ver_b->dest.y)
		diff.sy = 1;
	else
		diff.sy = -1;
	diff.err = diff.dx - diff.dy;
	paint_line(ver_a, ver_b, image, diff);
}

void	print_lines(t_vertex **matrix, int *rows, mlx_image_t *image)
{
	int	x;
	int	y;
	int	lenght;
	int	next_len;

	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		if (y + 1 < *rows)
			next_len = matrix[y + 1][0].len;
		while (x < lenght)
		{
			if (x + 1 < lenght)
				new_line(&matrix[y][x], &matrix[y][x + 1], image);
			if (y + 1 < *rows)
			{
				if (next_len > x)
					new_line(&matrix[y][x], &matrix[y + 1][x], image);
			}
			x++;
		}
		y++;
	}
}

void	error_exit(mlx_t *mlx)
{
	mlx_close_window(mlx);
	puts(mlx_strerror(mlx_errno));
}

int32_t	print_matrix(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	static mlx_image_t	*image;
	mlx_t				*mlx;

	calc_img_size(mmsizes, matrix, rows);
	mlx = mlx_init(1600, 900, "FdF", true);
	if (!mlx)
		return (EXIT_FAILURE);
	image = mlx_new_image(mlx, 1500, 850);
	if (!image)
	{
		error_exit(mlx);
		return (EXIT_FAILURE);
	}
	print_lines(matrix, rows, image);
	if (mlx_image_to_window(mlx, image, 50, 45) == -1)
	{
		error_exit(mlx);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(mlx, &close_window, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
