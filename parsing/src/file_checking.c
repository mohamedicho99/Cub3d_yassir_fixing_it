/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:31:43 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:31:43 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ends_with(char *s, char *target)
{
	int	target_len;
	int	s_len;

	s_len = ft_strlen(s) - 1;
	target_len = ft_strlen(target) - 1;
	if (target_len <= 0 || s_len <= 0)
		return (0);
	while (target_len >= 0 && s_len >= 0)
	{
		if (s[s_len] != target[target_len])
			return (0);
		s_len--;
		target_len--;
	}
	if (s[s_len] == '/')
		return (0);
	return (1);
}

void	check_is_fd_valid(t_data *data, char *ext_str)
{
	int	fd;

	if (ext_str)
	{
		fd = open(ext_str, O_RDONLY);
		if (fd <= 0)
			ft_exit_failure(data, "{-} Cannot open map/xpm file!");
		close(fd);
	}
}

void	check_is_directory(t_data *data, char *path)
{
	int	fd;

	if (path)
	{
		fd = open(path, O_DIRECTORY);
		if (fd >= 0)
		{
			close(fd);
			ft_exit_failure(data, "{-} map/xpm file provided is a direcotry!");
		}
	}
}

void	check_file_validity(t_data *data, char *file_str)
{
	check_is_directory(data, file_str);
	check_cub_extention(data, file_str);
	check_is_fd_valid(data, file_str);
}
