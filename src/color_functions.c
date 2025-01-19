/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:17:22 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/24 20:54:37 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	strhex_to_uint(char *str, uint32_t *color)
{
	uint32_t	num;
	char		c;

	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		str += 2;
		num = 0;
		while (str)
		{
			c = *str;
			if (ft_isalnum(c))
			{
				if (ft_isdigit(c))
					num = num * 16 + (c - '0');
				else
					num = num * 16 + (ft_toupper(c) - 'A' + 10);
			}
			else
				break ;
			str++;
		}
		*color = num;
	}
	return (0);
}

uint32_t	color(int dist, uint32_t start, uint32_t end, int i)
{
	static uint32_t	calc_color;
	int				pos;
	long			power;
	int				aux[2];
	static int		c;

	if (i == 0)
		c = 0;
	calc_color = start;
	power = 1;
	pos = 1;
	while (pos <= 4)
	{
		aux[0] = start % 256;
		aux[1] = end % 256;
		calc_color += (aux[1] - aux[0]) / dist * power * c;
		start /= 256;
		end /= 256;
		power *= 256;
		pos++;
	}
	c++;
	return (calc_color);
}

void	capture_init_color(char *str, uint32_t *color)
{
	char	*str_col;

	str_col = ft_strchr(str, ',');
	if (str_col)
	{
		str_col++;
		if (str_col)
			strhex_to_uint(str_col, color);
	}
	else
		*color = 0xFFFFFFFF;
}
