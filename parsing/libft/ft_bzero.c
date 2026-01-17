/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:00:53 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/18 10:15:45 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	cc;
	size_t			i;

	ptr1 = (unsigned char *)s;
	cc = 0;
	i = 0;
	while (i != n)
	{
		ptr1[i] = cc;
		i++;
	}
}
