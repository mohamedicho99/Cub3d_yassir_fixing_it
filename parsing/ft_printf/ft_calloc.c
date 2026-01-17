/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 06:07:14 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/01/08 03:52:31 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;
	size_t			i;

	ptr = (unsigned char *)s;
	c = 0;
	i = 0;
	while (i != n)
	{
		ptr[i] = c;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;
	size_t	total_len;

	total_len = nmemb * size;
	if (size != 0 && total_len / size != nmemb)
		return (NULL);
	space = malloc(total_len);
	if (!space)
		return (NULL);
	ft_bzero(space, nmemb * size);
	return (space);
}
