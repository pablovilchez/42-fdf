/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:41:36 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/19 20:25:05 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lst(char **strlst)
{
	int	i;

	i = 0;
	while (strlst[i])
	{
		free (strlst[i]);
		i++;
	}
	free (strlst);
}
