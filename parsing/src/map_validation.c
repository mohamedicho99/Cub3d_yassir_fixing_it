/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:28:06 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:28:06 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_valid_map_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'S' && data->map[i][j] != 'N'
				&& data->map[i][j] != 'W' && data->map[i][j] != 'E'
				&& data->map[i][j] != ' ')
			{
				ft_exit_failure(data, "{-} Invalid map char found!");
			}
			j++;
		}
		i++;
	}
}

void	one_player_only_map(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'S' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		ft_exit_failure(data, "{-} Map should have exactly one player!");
}

void	find_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'S' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->player_position.y = i;
				data->player_position.x = j;
				data->player_char = data->map[i][j];
			}
			j++;
		}
		i++;
	}
}

int	is_map_empty(t_data *data)
{
	if (data->map_width == 1)
		ft_exit_failure(data, "{-} no map detected");
	return (1);
}

void	map_validation(t_data *data)
{
	is_map_empty(data);
	is_valid_map_char(data);
	one_player_only_map(data);
	find_player_position(data);
}
// printf("player x: %d\n", data->player_position.x);
// printf("player y: %d\n", data->player_position.y);
// TODO: is map empty
// TODO; is map the last item on the file
//
// give it an empty file and valid file with no map or empty map
// take a look at the values return by get 
// 		next line for the file and protect against that
// do the same with map ,
// what will data->map have is meets end of line ? 
//				it will still be null right ?
// map comes after all textures and colors in file
