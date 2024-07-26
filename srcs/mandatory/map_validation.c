/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:37:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/26 15:35:31 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	check_map_name(char *map_name)
{
	int	i;

	i = 0;
	if (map_name == NULL)
		return (-1);
	if (map_name[0] == '\0')
		return (-1);
	while (map_name[i] != '\0')
		i++;
	if (map_name[i - 1] != 'b' || map_name[i - 2] != 'u' || map_name[i - 3] != 'c' || map_name[i - 4] != '.')
		return (-1);
	return (0);
}

int	copy_file_contents(t_data *data, char *map_name)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		data->map->file[i] = ft_strdup(line);
		i++;
	}
	data->map->file[i] = NULL;
	close(fd);
	return (0);
}

int	check_map_hight(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	data->map_height = 0;
	if (data->map->file[i] == NULL)
		return (-1);
	while (data->map->file[i] != NULL)
		i++;
	i--;
	while (i > 0)
	{
		line = data->map->file[i];
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ' || line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
		{
			data->map_height++;
			i--;
		}
		else
			break ;
	}
	if (i < 6 || data->map_height == 0)
		return (-1);
	data->map->
}

int	check_texture_paths(t_data *data, char *map_name)
{
	if (data->map->texture_path_e == NULL || data->map->texture_path_n == NULL || data->map->texture_path_s == NULL || data->map->texture_path_w == NULL)
		return (-1);
	if(data->map->floor_color == NULL || data->map->ceiling_color == NULL)
		return (-1);
	return (0);
}

void    is_map_valid(t_data *data, char *map_name)
{
	if (check_map_name(map_name) < 0)
		error_exit(data, "Map name is invalid", 0);
	if (copy_file_contents(data, map_name) < 0)
		error_exit(data, "Map file could not be opened", 0);
	if (check_map_syntax(data) < 0)
		error_exit(data, "Map syntax is invalid", 0);
	if (check_texture_paths(data, map_name) < 0)
		error_exit(data, "Texture paths are missing", 0);
    if (map_name == NULL)
        return ;

}