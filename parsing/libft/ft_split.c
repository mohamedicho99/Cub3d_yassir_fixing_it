/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <mohel-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:15:52 by mohel-mo          #+#    #+#             */
/*   Updated: 2024/11/18 10:15:33 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define OUT 0
#define IN 1

static size_t	al_strlen(const char *s, char c, size_t start)
{
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	while (s[i] && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

size_t	ft_count(const char *s, const char c)
{
	size_t	state;
	size_t	count;
	size_t	i;

	count = 0;
	state = OUT;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			state = OUT;
		else
		{
			if (state == OUT)
			{
				count++;
				state = IN;
			}
		}
		i++;
	}
	return (count);
}

static void	fail_safe(char **matrix_at_j, size_t j)
{
	char	**start;

	start = matrix_at_j;
	while (j--)
		free(start[j]);
	free(start);
}

static size_t	allocate_word(char const *s, char c, size_t *ct,
		char **matrix_at_j)
{
	while (s[*ct] == c && s[*ct])
		(*ct)++;
	if (s[*ct] != c && s[*ct])
	{
		*matrix_at_j = ft_substr(s, *ct, al_strlen(s, c, *ct));
		if (!*matrix_at_j)
			return (0);
		while (s[*ct] != c && s[*ct])
			(*ct)++;
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	ct;
	size_t	j;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	ct = ft_count(s, c);
	matrix = malloc(sizeof(char *) * (ct + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ct > j)
	{
		if (!allocate_word(s, c, &i, &matrix[j]))
		{
			fail_safe(matrix, j);
			return (NULL);
		}
		j++;
	}
	matrix[j] = NULL;
	return (matrix);
}
