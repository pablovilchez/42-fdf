/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:42:23 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/29 10:47:36 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_leaks(void)
{
	system("leaks -q fdf");
}

int	main(int argc, char *argv[])
{
	t_vertex	**matrix;
	t_mmsizes	mmsizes;
	int			rows;

	atexit (ft_leaks);
	matrix = get_matrix(argc, argv, &rows);
	if (matrix)
	{
		start_matrix(matrix, &rows, &mmsizes);
		if (check_size(matrix, rows) == 0)
			print_matrix(matrix, &rows, &mmsizes);
		else
			ft_printf("Minimum matrix size is 3x3.\n");
		free_matrix(matrix, &rows);
	}
	ft_printf("End of FdF program\n");
	return (0);
}
