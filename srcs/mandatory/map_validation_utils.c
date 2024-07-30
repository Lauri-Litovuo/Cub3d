/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:06:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/30 15:31:53 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	check_map_syntax(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j].type != '1'
				&& data->map[i][j].type != '0' && data->map[i][j].type != ' ')
				sys_error_exit(data, "Invalid map syntax", 0);
			j++;
		}
		i++;
	}
}

void	get_widest_width(t_data *data)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j].type != '\0')
			j++;
		if (j > width)
			width = j;
		i++;
	}
	data->map_width = width;
}

void	allocate_map(t_data *data)
{
	int	i;

	data->map = malloc((data->map_height) * sizeof(t_map));
	if (data->map == NULL)
		sys_error_exit(data, "Malloc failed", 0);
	i = 0;
	get_widest_width(data);
	while (i + data->info_lines_count < data->map_height)
	{
		data->map[i] = malloc((data->map_width) * sizeof(t_map));
		if (data->map[i] == NULL)
			sys_error_exit(data, "Malloc failed", 0);
		i++;
	}
}

int	assign_map_contents(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = data->info_lines_count;
	k = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->file[i][j] != '\0')
		{
			data->map[k][j].type = data->file[i][j];
			j++;
		}
		while (j < data->map_width)
		{
			data->map[k][j].type = ' ';
			j++;
		}
		i++;
		k++;
	}
	return (0);
}

int	check_texture_paths(t_data *data, char *map_name)
{
	if (data->texture_path_e == NULL
		|| data->texture_path_n == NULL || data->texture_path_s == NULL
		|| data->texture_path_w == NULL)
		return (-1);
	if (data->floor_color == NULL || data->ceiling_color == NULL)
		return (-1);
	return (0);
}

