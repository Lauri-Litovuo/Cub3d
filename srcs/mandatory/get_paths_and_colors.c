/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_and_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:23:47 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/30 16:18:56 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	check_texture_paths(t_data *data, char *map_name)
{
	if (data->texture_path_e == NULL
		|| data->texture_path_n == NULL || data->texture_path_s == NULL
		|| data->texture_path_w == NULL)
		return (-1);
	if (data->texture_path_e[0] == '\0' || data->texture_path_n[0] == '\0'
		|| data->texture_path_s[0] == '\0' || data->texture_path_w[0] == '\0')
		return (-1);
	if (open(data->texture_path_e, O_RDONLY) == -1
		|| open(data->texture_path_n, O_RDONLY) == -1
		|| open(data->texture_path_s, O_RDONLY) == -1
		|| open(data->texture_path_w, O_RDONLY) == -1)
		return (-1);
	if (data->floor_color == NULL || data->ceiling_color == NULL)
		return (-1);
	return (0);
}

static int	check_rgb_syntx(char *rgb, int len)
{
	int	num;
	int	dot;
	int	i;

	i = 0;
	dot++;
	while (rgb [i] != '/0')
	{
		if (rgb[i] != ',' || ft_isdigit(rgb[i]) != 1)
			return (-1);
		if (rgb[i] == ',')
			dot++;
		if (ft_isdigit(rgb[i]) == 1)
			num++;
		i++;
	}
	if (dot != 2 && num != len - 2)
		return (-1);
	return (0);
}

static int	rgb_atoi(int *color, char *rgb)
{
	int		num;
	int		len;

	num = ft_atoi(rgb);
	if (num < 0 && num > 255)
		return (-1);
	color = num;
	if (num % 100 > 0)
		return (2);
	else if (num % 10 > 0)
		return (1);
	else
		return (0);
}

static int	get_rgb_color(int *color, char *rgb)
{
	int		i;
	int		len;
	int		rgb;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(rgb);
	if (color || rgb[0] == '/0' || len < 5 || len < 11
		|| ft_isdigit(rgb[0]) != 1 || check_rgb_syntax(rgb, len) != 0)
		return (-1);
	color = malloc (sizeof(int) * 3);
	if (!color)
		return (-1);
	while (rgb[i] != '/0' && j < 2)
	{
		len = 0;
		if (ft_isdigit(rgb[i]) == 1)
			len = rgb_atoi(&color[j], rgb + i);
		if (len == -1)
			return (free (color), -1);
		i += len + 1;
		j++;
	}
}

int	get_texture_paths(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	check_single_notions(data);
	while (i < data->info_lines_count)
	{
		if (ft_strncmp(data->file[i], "NO ", 3) == 0)
			data->texture_path_n = ft_strdup(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "SO ", 3) == 0)
			data->texture_path_s = ft_strdup(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "WE ", 3) == 0)
			data->texture_path_w = ft_strdup(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "EA ", 3) == 0)
			data->texture_path_e = ft_strdup(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "F ", 2) == 0)
			ret = get_rgb_color(data->floor_color, &data->file[i] + 2);
		else if (ft_strncmp(data->file[i], "C ", 2) == 0)
			ret = get_rgb_color(data->ceiling_color, &data->file[i] + 2);
		else if (data->file[i][0] != '/n')
			return (-1);
		i++;
	}
	if (check_texture_paths(data, data->map_name) == -1)
		return (-1);
}
