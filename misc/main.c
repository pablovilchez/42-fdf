/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:38:39 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/19 17:41:53 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 512
#define HEIGHT 512

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	main(void)
{
	static mlx_image_t	*image;
	mlx_t				*mlx;
	uint32_t			i;
	double				secs;
	

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	image = mlx_new_image(mlx, 128, 128);
	if (!image)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	i = 48;
	if(mlx_is_key_down(mlx, 65))
	{
		while(i < 100)
		{
			mlx_put_pixel(image, i, 48, 0x00FFFFFF);
			i++;
		}
	}
	mlx_put_string(mlx, "Hola", 50, 50);
	mlx_set_window_pos(mlx, 700, 300);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
