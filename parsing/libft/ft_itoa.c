/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:00:50 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/18 10:15:20 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n)
{
	long	nb;
	size_t	i;

	nb = n;
	i = 1;
	if (nb < 0)
		i++;
	while (nb / 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static size_t	ft_putnbr(int n, char *re, size_t pos)
{
	long	nb;

	nb = n;
	if (nb == 0)
	{
		re[pos] = '0';
		return (pos + 1);
	}
	if (nb < 0)
	{
		re[pos++] = '-';
		nb = -nb;
	}
	if (nb > 9)
	{
		pos = ft_putnbr(nb / 10, re, pos);
		pos = ft_putnbr(nb % 10, re, pos);
	}
	else
		re[pos++] = nb + '0';
	return (pos);
}

char	*ft_itoa(int n)
{
	size_t	nl;
	char	*result;

	nl = n_len(n);
	result = malloc(sizeof(char) * (nl + 1));
	if (!result)
		return (NULL);
	ft_putnbr(n, result, 0);
	result[nl] = '\0';
	return (result);
}
