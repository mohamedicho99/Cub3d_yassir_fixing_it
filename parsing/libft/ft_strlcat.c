/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 03:52:29 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/19 18:07:40 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	i = 0;
	j = 0;
	dst_len = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (dst[i])
		i++;
	dst_len = i;
	if (dst_len >= size)
		return (src_len + size);
	while (src[j] && j < (size - dst_len - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
