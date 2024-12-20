/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:03:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/17 13:03:47 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	change_door_status(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (data->map_height))
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (data->map[y][x].type == 'D')
			{
				data->map[y][x].type = '1';
				data->map[y][x].is_door = 1;
			}
		}
	}
}

void	init_map_flags(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (data->map_height))
	{
		x = -1;
		while (++x < data->map_width)
		{
			data->map[y][x].is_door = 0;
			data->map[y][x].is_open = 0;
			data->map[y][x].is_opening = 0;
			data->map[y][x].is_closing = 0;
			data->map[y][x].open_img_iter = -1;
			data->map[y][x].is_enemy = 0;
			data->map[y][x].is_exit = 0;
		}
	}
}
