/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 06:07:01 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/01/12 09:29:34 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_sac(char c, va_list args, int *counter)
{
	char	*s;
	char	nc;

	if (c == 's')
	{
		s = va_arg(args, char *);
		ft_putstr(s, counter);
	}
	if (c == 'c')
	{
		nc = va_arg(args, int);
		ft_putchar(nc, counter);
	}
}

static void	handle_nums(char c, va_list args, int *counter)
{
	int				nd;
	unsigned int	uid;

	if (c == 'd' || c == 'i')
	{
		nd = va_arg(args, int);
		ft_putnbr(nd, counter);
	}
	if (c == 'u')
	{
		uid = va_arg(args, unsigned int);
		ft_putnbr_un(uid, counter);
	}
}

static void	handle_pahex(char c, va_list args, int *counter)
{
	void			*ptr;
	unsigned int	n;

	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		ft_putptr((unsigned long)ptr, counter);
	}
	if (c == 'x')
	{
		n = va_arg(args, unsigned int);
		ft_puthex((unsigned int)n, 'x', counter);
	}
	if (c == 'X')
	{
		n = va_arg(args, unsigned int);
		ft_puthex((unsigned int)n, 'X', counter);
	}
}

static void	format(char c, va_list args, int *counter)
{
	handle_sac(c, args, counter);
	handle_nums(c, args, counter);
	handle_pahex(c, args, counter);
	if (c == '%')
		ft_putchar('%', counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		counter;
	int		i;

	if (!s)
		return (-1);
	va_start(args, s);
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (-1);
			format(s[i + 1], args, &counter);
			i++;
		}
		else
			ft_putchar(s[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
