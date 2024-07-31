/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:06:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/31 09:24:53 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	assign_player_position(t_data *data, int x, int y)
{
	data->player_x_pos = x;
	data->player_y_pos = y;
	data->player_flag = 1;
}

void	check_map_syntax(t_data *data)
{
	int	i;
	int	j;
	int	player_flag;

	i = 0;
	player_flag = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (ft_strchr("10NESWX", data->map[i][j].type) == NULL)
				sys_error_exit(data, "Invalid map syntax", 0);
			if ((data->map[i][j].type == 'E' || data->map[i][j].type == 'N'
				|| data->map[i][j].type == 'W' || data->map[i][j].type == 'S'))
			{
				if (data->player_flag == 0)
					assign_player_position (data, j, i);
				else
					sys_error_exit(data, "Too many players", 0);
			}
			j++;
		}
		i++;
	}
}

static void	get_widest_width(t_data *data)
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
