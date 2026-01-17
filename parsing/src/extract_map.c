/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:36:35 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:36:35 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_config_line(char *line)
{
	if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "EA ", 3)
		|| ft_strnstr(line, "SO ", 3) || ft_strnstr(line, "WE ", 3))
	{
		return (1);
	}
	if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2))
	{
		return (1);
	}
	return (0);
}

int	return_map_index(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->file_data[i])
	{
		if (is_config_line(data->file_data[i]))
			j++;
		i++;
	}
	return (j);
}

void	rm_newline_from_map_lines(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '\n')
				data->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	extract_map(t_data *data)
{
	int	start_index;
	int	i;
	int	j;

	start_index = return_map_index(data) + 1;
	i = start_index;
	get_map_width(data, start_index);
	get_map_height(data, start_index);
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		ft_exit_failure(data, "map allocation failed!");
	data->map[data->map_height] = NULL;
	j = 0;
	while (data->file_data[i])
	{
		data->map[j] = ft_strdup(data->file_data[i]);
		if (!data->map[j])
			ft_exit_failure(data, "map allocation failed!");
		i++;
		j++;
	}
	rm_newline_from_map_lines(data);
}
