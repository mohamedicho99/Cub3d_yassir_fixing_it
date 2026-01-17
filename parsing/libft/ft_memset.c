/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 01:53:24 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/19 16:11:16 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	cc;
	size_t			i;

	ptr1 = (unsigned char *)b;
	cc = (unsigned char)c;
	i = 0;
	while (i != len)
	{
		ptr1[i] = cc;
		i++;
	}
	return (b);
}
