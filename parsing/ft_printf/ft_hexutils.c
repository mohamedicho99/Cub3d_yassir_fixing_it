/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 06:07:23 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/01/11 10:55:00 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	wprefix(int *counter)
{
	write(1, "0x", 2);
	*counter += 2;
}

static void	ft_strcpy(char *src, char *dst)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_putptr(unsigned long n, int *counter)
{
	if (!n)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	wprefix(counter);
	ft_puthexptr(n, counter);
}

void	ft_puthexptr(unsigned long n, int *counter)
{
	char	*num;
	int		num_len;
	int		i;
	char	hex[17];

	ft_strcpy("0123456789abcdef", hex);
	num = ft_calloc(sizeof(char), 21);
	if (!num)
		return ;
	i = 0;
	while (n && i < 16)
	{
		num[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	num_len = ft_strlen(num);
	while (num_len--)
		ft_putchar(num[num_len], counter);
	free(num);
}

void	ft_puthex(unsigned int n, char con, int *counter)
{
	char	*num;
	int		num_len;
	int		i;
	char	hex[17];

	ft_strcpy("0123456789abcdef", hex);
	if (con == 'X')
		ft_strcpy("0123456789ABCDEF", hex);
	num = ft_calloc(sizeof(char), 21);
	if (!num)
		return ;
	i = 0;
	if (n == 0)
		num[0] = '0';
	while (n && i < 16)
	{
		num[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	num_len = ft_strlen(num);
	while (num_len--)
		ft_putchar(num[num_len], counter);
	free(num);
}
