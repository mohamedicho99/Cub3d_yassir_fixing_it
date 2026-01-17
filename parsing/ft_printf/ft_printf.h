/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 06:07:32 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/01/11 10:35:38 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putnbr(long n, int *counter);
void	ft_putnbr_un(unsigned int n, int *counter);
void	ft_putchar(char c, int *counter);
int		ft_strlen(const char *s);
void	ft_puthex(unsigned int n, char con, int *counter);
void	ft_puthexptr(unsigned long n, int *counter);
void	ft_putptr(unsigned long n, int *counter);
void	ft_putstr(const char *s, int *counter);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
