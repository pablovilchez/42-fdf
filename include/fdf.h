/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:40:09 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/29 10:48:02 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include "../assets/libft/include/libft.h"
#include "../assets/MLX42/include/MLX42/MLX42.h"

typedef struct s_s_exit
{
	mlx_t			*mlx;
	mlx_key_data_t	keydata;
}					t_s_exit;


typedef struct s_max_min_matrix
{
	int				max_x;
	int				min_x;
	int				max_y;
	int				min_y;
	uint32_t		image_x;
	uint32_t		image_y;
}					t_mmsizes;


typedef struct s_differences
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
}					t_diff;

typedef struct s_axis
{
	int				x;
	int				y;
}					t_axis;

typedef struct s_vertex
{
	int				high;
	int				len;
	uint32_t		color;
	t_axis			start;
	t_axis			dest;
}					t_vertex;

// get_matrix.c
t_vertex	**get_matrix(int argc, char *argv[], int *rows);
char		*file_to_str(int filefd);
t_vertex	**text_to_matrix(char *get_text, int *rows);
t_vertex	**lines_to_vertex(char **lines, int total_y);
int			count_elements(char **line);
// start_matrix.c
void		make_isometric(t_vertex **matrix, int *rows);
void		line_len(t_vertex *matrix_line, int line_len);
void		start_matrix(t_vertex **matrix, int *rows, t_mmsizes *mmsizes);
// color_functions.c
void		capture_init_color(char *str, uint32_t *color);
uint32_t	color(int dist, uint32_t start, uint32_t end, int i);
uint32_t	strhex_to_uint(char *str, uint32_t *color);
// print_matrix.c
int32_t		print_matrix(t_vertex **matrix, int *rows, t_mmsizes *mmsizes);
void		error_exit(mlx_t *mlx);
void		print_lines(t_vertex **matrix, int *rows, mlx_image_t *image);
void		new_line(t_vertex *ver_a, t_vertex *ver_b, mlx_image_t *image);
void		paint_line(t_vertex *a, t_vertex *b, mlx_image_t *img, t_diff diff);
// free_matrix.c
void		free_matrix(t_vertex **matrix, int *rows);
// utils.c
int			pix_num(t_vertex *v_a, t_vertex *v_b, t_diff diff);
int			count_pix(t_vertex *vertex_a, t_vertex *vertex_b);
void		close_window(mlx_key_data_t keydata, void *mlx);
int			check_size(t_vertex **matrix, int rows);
// adjust_values.c
void		adjust_values(t_vertex **matrix, int *rows, t_mmsizes *mmsizes);
void		calc_minims(t_vertex **matrix, int *rows, t_mmsizes *mmsizes);
void		calc_maxims(t_vertex **matrix, int *rows, t_mmsizes *mmsizes);
void		calc_img_size(t_mmsizes *mmsizes, t_vertex **matrix, int *rows);
void		reduce_size(t_vertex **matrix, int *rows, int factor);
