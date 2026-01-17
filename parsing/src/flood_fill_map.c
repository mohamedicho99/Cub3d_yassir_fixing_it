/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:31:35 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:31:35 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_map_copy(t_data *data)
{
	int	i;

	i = 0;
	data->map_copy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map_copy)
		ft_exit_failure(data, "{-} Failed to allocate memory for map copy!");
	data->map_copy[data->map_height] = NULL;
	while (data->map && data->map[i])
	{
		data->map_copy[i] = ft_strdup(data->map[i]);
		if (!data->map[i])
			ft_exit_failure(data, "{-} Failed to allocate memory for map row");
		i++;
	}
}

void	flood_fill(t_data *data, int pos_x, int pos_y, char player_char)
{
	if ((pos_x < 0 || pos_y < 0) || (pos_x >= data->map_width - 1)
		|| (pos_y >= data->map_height))
		return ;
	if (data->map_copy[pos_y][pos_x] == '1'
		|| data->map_copy[pos_y][pos_x] == 'X')
		return ;
	if (data->map_copy[pos_y][pos_x] == ' '
		|| data->map_copy[pos_y][pos_x] == '\0')
		ft_exit_failure(data, "{-} Error , went out of bounds");
	data->map_copy[pos_y][pos_x] = 'X';
	flood_fill(data, pos_x + 1, pos_y, player_char);
	flood_fill(data, pos_x - 1, pos_y, player_char);
	flood_fill(data, pos_x, pos_y - 1, player_char);
	flood_fill(data, pos_x, pos_y + 1, player_char);
}

void	invoke_flood(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->player_position.x;
	pos_y = data->player_position.y;
	flood_fill(data, pos_x, pos_y, data->player_char);
}
