/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:20:34 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/18 19:10:11 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_void(void *p)
{
	size_t	count;

	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	count += print_hex_long((unsigned long long)p);
	return (count);
}
