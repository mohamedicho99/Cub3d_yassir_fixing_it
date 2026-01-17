/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:05:39 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/20 23:39:08 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
