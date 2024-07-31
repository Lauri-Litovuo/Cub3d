/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:42:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/31 11:39:49 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	check_for_nl(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (ft_strchr("10SNEW ", *str) != 0)
			str++;
		else
			return (1);
	}
	return (0);
}

int	check_first_last(char *str)
{
	while (*str)
	{
		if (*str != '1' && *str != ' ')
			return (-1);
		str++;
	}
	return (0);
}

int	check_surrounding_tiles(char **tile, int x_pos)
{
	if (tile[-1][x_pos - 1] == ' ' || tile[-1][x_pos - 1] == 0)
		return (-1);
	if (tile[-1][x_pos] == ' ' || tile[-1][x_pos] == 0)
		return (-1);
	if (tile[-1][x_pos + 1] == ' ' || tile[-1][x_pos + 1] == 0)
		return (-1);
	if (tile[0][x_pos - 1] == ' ' || tile[0][x_pos - 1] == 0)
		return (-1);
	if (tile[0][x_pos] == ' ' || tile[0][x_pos] == 0)
		return (-1);
	if (tile[0][x_pos + 1] == ' ' || tile[0][x_pos + 1] == 0)
		return (-1);
	if (tile[1][x_pos - 1] == ' ' || tile[1][x_pos - 1] == 0)
		return (-1);
	if (tile[1][x_pos] == ' ' || tile[1][x_pos] == 0)
		return (-1);
	if (tile[1][x_pos + 1] == ' ' || tile[1][x_pos + 1] == 0)
		return (-1);
	return (0);
}

int	check_if_map_closed(char **map_line)
{
	int	i;

	i = 0;
	while (map_line[0][i])
	{
		if (strchr("10SNEW", map_line) != NULL)
		{
			if (check_surrounding_tiles(map_line, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_map_borders(t_data *data)
{
	int	i;

	i = 0;
	while (check_for_nl == 0)
	{
		if (i == 0 && check_first_last(data->map_lines[i]) == -1)
			return (-1);
		else if (i == data->map_height - 1 && check_first_last(data->map_lines[i]) == -1)
			return (-1);
		else
		{
			if (check_if_map_closed(&data->map_lines[i]) == -1)
				return (-1);
		}
	}
	return (0);
}
