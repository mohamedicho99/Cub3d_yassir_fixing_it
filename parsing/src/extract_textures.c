/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:33:17 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 23:33:17 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_no_texture(t_data *data, char *line)
{
	char	*text;
  char  *index;

	text = NULL;
	index = NULL;
	if ((index = ft_strnstr(line, "NO ", ft_strlen(line))))
	{
		if (data->no_texture)
			ft_exit_failure(data, "{-} duplicated texture!");
		text = ft_strtrim(index + 3, " \t\n");
		data->no_texture = ft_strdup(text);
		free(text);
		text = NULL;
	}
}

void	get_so_texture(t_data *data, char *line)
{
	char	*text;
  char  *index;

	text = NULL;
	index = NULL;
	if ((index = ft_strnstr(line, "SO ", ft_strlen(line))))
	{
		if (data->so_texture)
			ft_exit_failure(data, "{-} duplicated texture!");
		text = ft_strtrim(index + 3, " \t\n");
		data->so_texture = ft_strdup(text);
		free(text);
		text = NULL;
	}
}

void	get_ea_texture(t_data *data, char *line)
{
	char	*text;
  char  *index;

	text = NULL;
	index = NULL;
	if ((index = ft_strnstr(line, "EA ", ft_strlen(line))))
	{
		if (data->ea_texture)
			ft_exit_failure(data, "{-} duplicated texture!");
		text = ft_strtrim(index + 3, " \t\n");
		data->ea_texture = ft_strdup(text);
		free(text);
		text = NULL;
	}
}

void	get_we_texture(t_data *data, char *line)
{
	char	*text;
  char  *index;

	text = NULL;
  index = NULL;
	if ((index = ft_strnstr(line, "WE ", ft_strlen(line))))
	{
		if (data->we_texture)
			ft_exit_failure(data, "{-} duplicated texture!");
		text = ft_strtrim(index + 3, " \t\n");
		data->we_texture = ft_strdup(text);
		free(text);
		text = NULL;
	}
}

void	extract_textures(t_data *data)
{
	int	i;

	i = 0;
	while (data->file_data[i])
	{
		get_no_texture(data, data->file_data[i]);
		get_so_texture(data, data->file_data[i]);
		get_ea_texture(data, data->file_data[i]);
		get_we_texture(data, data->file_data[i]);
		i++;
	}
}
// you can use the same technique to extract Floor and ceiling chars
// and for the rgb colors, you can use split by comma
// and then use strtrim the spaces again
