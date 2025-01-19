/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:53:00 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/29 10:54:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_elements(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

t_vertex	**lines_to_vertex(char **lines, int total_y)
{
	int			y;
	int			total_x;
	t_vertex	**matrix;
	char		**line;

	y = 0;
	matrix = (t_vertex **)ft_calloc(total_y, sizeof(t_vertex *));
	while (lines[y])
	{
		line = ft_split(lines[y], ' ');
		total_x = count_elements(line);
		matrix[y] = (t_vertex *)ft_calloc(total_x, sizeof(t_vertex));
		line_len(matrix[y], total_x);
		total_x = 0;
		while (line[total_x])
		{
			matrix[y][total_x].high = ft_atoi(line[total_x]);
			capture_init_color(line[total_x], &matrix[y][total_x].color);
			total_x++;
		}
		y++;
		ft_free_lst(line);
	}
	return (matrix);
}

t_vertex	**text_to_matrix(char *get_text, int *rows)
{
	char		**lines;
	int			total_y;
	t_vertex	**matrix;

	total_y = 0;
	lines = ft_split(get_text, '\n');
	while (lines[total_y])
		total_y++;
	*rows = total_y;
	matrix = lines_to_vertex(lines, total_y);
	ft_free_lst(lines);
	return (matrix);
}

char	*file_to_str(int filefd)
{
	char	*get_text;
	char	*buffer;
	char	*aux;

	get_text = (char *)ft_calloc(1, sizeof(char));
	buffer = ft_get_next_line(filefd);
	while (buffer)
	{
		aux = get_text;
		get_text = ft_strjoin(get_text, buffer);
		free(aux);
		free(buffer);
		buffer = ft_get_next_line(filefd);
	}
	return (get_text);
}

t_vertex	**get_matrix(int argc, char *argv[], int *rows)
{
	int			filefd;
	char		*get_text;
	t_vertex	**matrix;

	if (argc != 2)
		ft_printf(" Error: bad arguments.\n example: ./fdf file.fdf\n");
	else
	{
		filefd = open(argv[1], O_RDONLY, 0777);
		if (filefd == -1)
			ft_printf(" Error opening file.\n");
		else
		{
			get_text = file_to_str(filefd);
			close(filefd);
			matrix = text_to_matrix(get_text, rows);
			free(get_text);
			return (matrix);
		}
	}
	return (NULL);
}
