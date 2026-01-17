/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premap_element_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:25:23 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:25:23 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	do_premap_elements_exist(t_data *data)
{
	if (data->floor[0] <= -1 || data->floor[1] <= -1 || data->floor[2] <= -1)
		ft_exit_failure(data, "{-} Please provide proper floor values!");
	if (data->ceiling[0] <= -1 || data->ceiling[1] <= -1 || data->ceiling[2]
		<= -1)
		ft_exit_failure(data, "{-01} Please provide proper ceiling values!");
	if (!data->no_texture || !data->so_texture
		|| !data->we_texture || !data->ea_texture)
		ft_exit_failure(data, "{-01} Please provide proper textures!");
}
