/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:26:20 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/18 10:24:00 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cc;

	i = 0;
	ptr = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == cc)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
