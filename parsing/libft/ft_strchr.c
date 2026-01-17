/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:03:08 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/18 10:16:45 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_null(unsigned char *ptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len)
	{
		if (*(ptr + i) == '\0')
			return ((char *)ptr + i);
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;
	unsigned char	cc;
	size_t			len;
	size_t			i;

	len = ft_strlen(s);
	ptr = (unsigned char *)s;
	cc = (unsigned char)c;
	if (cc == '\0')
		return (handle_null(ptr, len));
	i = 0;
	while (ptr[i] && cc != '\0')
	{
		if (ptr[i] == cc)
			return ((char *)ptr + i);
		i++;
	}
	return (NULL);
}
