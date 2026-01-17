/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:32:10 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:32:10 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_xpm_extention(t_data *data, char *texture)
{
	if (!ends_with((char *)texture, ".xpm"))
		ft_exit_failure(data, "{-} Invalid xpm file!");
}

void	check_cub_extention(t_data *data, char *texture)
{
	if (!ends_with((char *)texture, ".cub"))
		ft_exit_failure(data, "{-} Invalid map file!");
}
