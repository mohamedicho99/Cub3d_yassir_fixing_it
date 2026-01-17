/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:11:14 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/18 10:19:50 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substr;
	size_t	j;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len || !len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	i = start;
	j = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[i] && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
