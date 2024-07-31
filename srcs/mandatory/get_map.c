/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/31 11:41:16 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	allocate_map(t_data *data)
{
	int	i;

	data->map = malloc((data->map_height) * sizeof(t_map));
	if (data->map == NULL)
		sys_error_exit(data, "Malloc failed", 0);
	i = data->info_lines_count;
	get_widest_width(data);
	while (i < data->map_height)
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
		if (j == 0 && i != data->map_height)
			return (-1);
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

void	free_2d_array_len(char **strs, int len)
{
	while (len >= 0)
	{
		free(strs[len]);
		len--;
	}
	free (strs);
}

int	create_map_lines(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = data->info_lines_count;
	k = 0;
	data->map_lines = malloc ((data->map_height + 1) * sizeof(char *));
	if (data->map_lines == NULL)
		return (-1);
	while (i < data->map_height)
	{
		data->map_lines[k] = ft_strdup(data->file[i]);
		if (!data->map_lines[k])
			return (free_map_lines(data->map_lines, k),-1);
		i++;
	}
	data->map_lines[k] = NULL;
	return (1);
}

void	change_spaces_to_x(t_data *data)
{
	int		x;
	int		y;
	t_map	**map;

	x = 0;
	y = 0;
	map = data->map;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (map[y][x].type == ' ')
				map[y][x].type = 'X';
			x++;
		}
		y++;
	}
}

int	copy_file_contents(t_data *data, char *map_name)
{
	int		fd;
	char	*line;
	int		i;

	data->file = malloc ((data->file_height + 1) * sizeof(char *));
	if (data->file == NULL)
		return (-1);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->file[i] = ft_strdup(line);
		free (line);
		i++;
	}
	data->file[i] = NULL;
	close(fd);
	return (0);
}

void	get_map(t_data *data, char *map_name)
{
	is_map_valid(data, map_name);
	if (copy_file_contents(data, map_name) == -1)
		error_exit(data, "Map file could not be opened", 0);
	allocate_map(data);
	assign_map(data);
	if (create_map_lines(data) < 0)
		sys_error_exit(data, "Malloc failed", 0);
	change_spaces_to_x(data);
	//print_map(data);
	check_map_syntax(data);
	if (data->player_flag == 0)
		error_exit(data, "No player", 0);
	if (check_map_borders(data) == -1)
		error_exit(data, "Map is not surrounded by walls", 0);
}
