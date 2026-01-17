/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_floor_and_ceiling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:37:32 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:37:32 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_floor_values(t_data *data, char **matrix)
{
	int		i;
	char	*re;

	i = 0;
	while (matrix[i])
	{
		re = ft_strtrim(matrix[i], " \n\t");
		data->floor[i] = ft_atoi(re);
		free(re);
		i++;
	}
}

void	get_floor_out_of_matrix(t_data *data, char **matrix)
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
			ft_exit_failure(data, "{-} Bad Floor values!");
		}
		if (ft_strlen(re) == 0)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad Floor values!");
		}
		free(re);
		i++;
	}
	set_floor_values(data, matrix);
	free_matrix(matrix);
}

void	get_ceiling(t_data *data, char *line)
{
	int		i;
	char	**matrix;

	i = 0;
	if (ft_strnstr(line, "C ", ft_strlen(line)))
	{
		if (data->ceiling[0] != -1)
			ft_exit_failure(data, "{-} Ceiling is duplicated!");
    // TODO: you use to split after 2 chars now you have to find the F and just from it
    // without that + 2 because  split takes care of the spaces for you 
		matrix = ft_split(line + 2, ',');
		while (matrix[i])
			i++;
		if (!matrix[0] || i < 3 || i > 3)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad ceiling values!!!!");
		}
		get_ceiling_out_of_matrix(data, matrix);
	}
}

void	get_floor(t_data *data, char *line)
{
	int		i;
	char	**matrix;

	i = 0;
	if (ft_strnstr(line, "F ", ft_strlen(line)))
	{
		if (data->floor[0] != -1)
			ft_exit_failure(data, "{-} Floor is duplicated!");
    // TODO: you use to split after 2 chars now you have to find the F and just from it
    // without that + 2 because  split takes care of the spaces for you 
		matrix = ft_split(line + 2, ',');
		while (matrix[i])
			i++;
		if (!matrix[0] || i < 3 || i > 3)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad Floor values!");
		}
		get_floor_out_of_matrix(data, matrix);
	}
}

void	extract_floor_and_ceiling(t_data *data)
{
	int	i;

	i = 0;
	while (data->file_data[i])
	{
		get_floor(data, data->file_data[i]);
		get_ceiling(data, data->file_data[i]);
		i++;
	}
}
