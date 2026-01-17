/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_floor_and_ceiling_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:37:50 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:37:50 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix[i])
		free(matrix[i]);
	if (matrix)
		free(matrix);
}

void	set_ceiling_values(t_data *data, char **matrix)
{
	int		i;
	char	*re;

	i = 0;
	while (matrix[i])
	{
		re = ft_strtrim(matrix[i], " \n\t");
		data->ceiling[i] = ft_atoi(re);
		free(re);
		i++;
	}
}

void	get_ceiling_out_of_matrix(t_data *data, char **matrix)
{
	int		i;
	char	*re;

	i = 0;
	while (matrix[i])
	{
		re = ft_strtrim(matrix[i], " \n\t");
		if (!validate_number(re))
		{
			free(re);
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad ceiling values!");
		}
		if (ft_strlen(re) == 0)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad ceiling values!!");
		}
		free(re);
		i++;
	}
	set_ceiling_values(data, matrix);
	free_matrix(matrix);
}
