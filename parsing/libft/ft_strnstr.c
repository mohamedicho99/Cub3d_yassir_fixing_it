/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:04:43 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/19 18:03:53 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*help(const char *big, const char *little, size_t len, size_t i)
{
	int	j;
	int	temp;

	j = 0;
	temp = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[j])
		{
			temp = i;
			while (big[i] == little[j] && big[i] && little[j] && i < len)
			{
				j++;
				i++;
			}
			if (little[j] == '\0')
				return ((char *)&big[temp]);
			j = 0;
			i = temp;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	return (help(big, little, len, i));
}
