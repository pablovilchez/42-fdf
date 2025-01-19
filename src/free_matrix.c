/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:01:58 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/29 10:11:32 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_vertex **matrix, int *rows)
{
	int	y;

	y = 0;
	while (y < *rows)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}
