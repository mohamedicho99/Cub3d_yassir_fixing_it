/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:29:47 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/18 10:23:32 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (n == 0)
		return (dst);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	ptr1 += n - 1;
	ptr2 += n - 1;
	i = n;
	if (dst > src)
	{
		while (i > 0)
		{
			*ptr1-- = *ptr2--;
			i--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
