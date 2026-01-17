/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:09:15 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/16 22:09:15 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: think about when to exit and when to return -1
// when an error that demands closing the program is met
// just exit, but make sure to have that inside a function that makes
// sure everything that needs to be freed is freed.

void	debug_printf(t_data *d)
{
	printf("file_str: %s\n", d->file_str ? "true" : "false");
	printf("file_data: %s\n", d->file_data ? "true" : "false");
	printf("NO: %s\n", d->no_texture);
	printf("SO: %s\n", d->so_texture);
	printf("WE: %s\n", d->we_texture);
	printf("EA: %s\n", d->ea_texture);
	printf("F: %d %d %d\n", d->floor[0], d->floor[1], d->floor[2]);
	printf("C: %d %d %d\n", d->ceiling[0], d->ceiling[1], d->ceiling[2]);
}

void	print_map(char **map, int height)
{
	int		x;
	char	c;

	for (int y = 0; y < height; y++)
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c == ' ')
				putchar('s');
			else
				putchar(c);
			x++;
		}
		putchar('\n');
	}
}

void	parsing(char *file_str, t_data *data)
{
	init_reset_data(data);
	data->file_str = file_str;
	check_file_validity(data, file_str);
	get_number_of_lines(file_str, data);
	get_file_data(data);
	extract_textures(data);
  validate_textures(data);
	extract_floor_and_ceiling(data);
	check_ranges(data);
	do_premap_elements_exist(data);
  printf("--------------- pre map stop sign --------------------\n");
	extract_map(data);
  print_map(data->map, data->map_height);
  //debug_printf(data);
  printf("{+} stop sign\n");
  exit(0);
	map_validation(data);
  printf("--------------- we got here sign --------------------\n");
	create_map_copy(data);
	invoke_flood(data);
	printf("map height : %d, map width : %d\n", data->map_height,
		data->map_width);
	printf("x : %d, y : %d\n", data->player_position.x,
		data->player_position.y);
	print_map(data->map_copy, data->map_height);
	// free_data(data);
}

static void	load_texture(e_data *data, int id, char *path)
{
	int	bpp;
	int	size_line;
	int	endian;

	data->textures[id] = mlx_xpm_file_to_image(data->mlx, path,
			&data->tex_width[id], &data->tex_height[id]);
	if (!data->textures[id])
	{
		ft_printf("Error: failed to load texture id %d\n", id);
		cleanup_and_exit(data);
		exit(1);
	}
	data->tex_data[id] = (int *)mlx_get_data_addr(data->textures[id], &bpp,
			&size_line, &endian);
}

void	init_textures(e_data *data, t_data *pdata)
{
	char	*paths[4];

	paths[NORTH] = pdata->no_texture;
	paths[SOUTH] = pdata->so_texture;
	paths[EAST] = pdata->ea_texture;
	paths[WEST] = pdata->we_texture;
	load_texture(data, NORTH, paths[NORTH]);
	load_texture(data, SOUTH, paths[SOUTH]);
	load_texture(data, EAST, paths[EAST]);
	load_texture(data, WEST, paths[WEST]);
}

/*void draw_scene_3d(e_data *data, t_data *p)
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		map_x;
	int		map_y;
	double	deltadistx;
	double	deltadisty;
	int		hit;
		int side;
	int		row_len;
		double perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
		int textureIndex;
		double wallx;
	int		tex_x;
	double	step;
	double	texpos;
	int		tex_y;
	int		color;

	for (int x = 0; x < WIDTH; x++)
	{
		// Calculate ray position and direction
		camerax = 2 * x / (double)WIDTH - 1;
		raydirx = data->dirx + data->planex * camerax;
		raydiry = data->diry + data->planey * camerax;
		map_x = (int)data->posx;
		map_y = (int)data->posy;
		deltadistx = fabs(1 / raydirx);
		deltadisty = fabs(1 / raydiry);
		double sidedistx, sidedisty;
		int stepx, stepy;
		hit = 0;
		// Determine step direction and initial side distance
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (data->posx - map_x) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (map_x + 1.0 - data->posx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (data->posy - map_y) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (map_y + 1.0 - data->posy) * deltadisty;
		}
		// --- DDA ---
		while (!hit)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				map_x += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				map_y += stepy;
				side = 1;
			}
			// bounds check for irregular maps
			if (map_y < 0 || map_y >= p->map_height)
				break ;
			row_len = ft_strlen(p->map[map_y]);
			if (map_x < 0 || map_x >= row_len)
				break ;
			if (p->map[map_y][map_x] == '1')
				hit = 1;
		}
		// Calculate perpendicular distance to wall
		if (side == 0)
			perpwalldist = sidedistx - deltadistx;
		else
			perpwalldist = sidedisty - deltadisty;
		if (perpwalldist < 1e-6)
			perpwalldist = 1e-6;
		// Calculate height of line to draw
		lineheight = (int)(HEIGHT / perpwalldist);
		// Calculate start and end positions on screen
		drawstart = -lineheight / 2 + HEIGHT / 2;
		if (drawstart < 0) drawstart = 0;
		drawend = lineheight / 2 + HEIGHT / 2;
		if (drawend >= HEIGHT) drawend = HEIGHT - 1;
		// Determine texture index based on wall side
		if (side == 0) // vertical wall
			textureIndex = (stepx > 0) ? EAST : WEST;
		else // horizontal wall
			textureIndex = (stepy > 0) ? SOUTH : NORTH;
		// Calculate exact point of wall hit
		if (side == 0)
			wallx = data->posy + perpwalldist * raydiry;
		else
			wallx = data->posx + perpwalldist * raydirx;
		wallx -= floor(wallx); // keep fractional part
		// X coordinate on texture
		tex_x = (int)(wallx * (double)data->tex_width[textureIndex]);
		if ((side == 0 && stepx < 0) || (side == 1 && stepy > 0))
			tex_x = data->tex_width[textureIndex] - tex_x - 1;
		// Step size for texture
		step = 1.0 * data->tex_height[textureIndex] / lineheight;
		texpos = (drawstart - HEIGHT / 2 + lineheight / 2) * step;
		// Draw vertical stripe
		for (int y = 0; y < HEIGHT; y++)
		{
			if (y < drawstart)
				my_pixel_put(data, x, y, data->c); // ceiling
			else if (y > drawend)
				my_pixel_put(data, x, y, data->f); // floor
			else
			{
				tex_y = (int)texpos & (data->tex_height[textureIndex] - 1);
				texpos += step;
				color = data->tex_data[textureIndex][tex_y
					* data->tex_width[textureIndex] + tex_x];
				my_pixel_put(data, x, y, color);
			}
		}
	}
}*/
int	render(e_data *data)
{
	ft_memset(data->addr, 0, HEIGHT * data->line_length);
	draw_scene_3d(data, data->pdata);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

// pdata for parsing data
// edata for execution data
int	main(int argc, char **argv)
{
	char	*file_str;
	t_data	pdata;
	e_data	edata;
	int		i;

	if (argc != 2)
	{
		printf("{-} Wrong Number of Args!\n");
		exit(1);
	}
	file_str = argv[1];
	parsing(file_str, &pdata);
	printf("{+} every thing is working as expected\n");
	printf("{+} parsing status: SUCCESS...\n");
  exit(1);
	init_data(&edata, &pdata);
	init_textures(&edata, &pdata);
	i = 0;
	while (i < 3)
	{
		printf("floor %d : %d, Ceiling %d : %d, \n", i, pdata.floor[i], i,
			pdata.ceiling[i]);
		i++;
	}
	mlx_loop_hook(edata.mlx, render, &edata);
	mlx_key_hook(edata.win, handle_key, &edata);
	mlx_hook(edata.win, 17, 0, handle_close, &edata);
	mlx_loop(edata.mlx);
	return (0);
}
