/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_and_colors_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:23:47 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/12 21:26:17 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int	check_texture_paths(t_data *data)
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
	if (data->floor_color == NULL || data->ceiling_col == NULL)
		return (-1);
	return (0);
}

static int	check_rgb_syntax(char *rgb, int len)
{
	int	num;
	int	dot;
	int	i;

	i = 0;
	dot = 0;
	num = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] != ',' && ft_isdigit(rgb[i]) != 1)
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

static int	get_rgb(t_color **color, char *rgb, int *flag, int i)
{
	int		len;
	int		j;

	j = -1;
	while (*rgb == ' ')
		rgb++;
	len = ft_strlen(rgb);
	if (*flag == 1 || rgb[0] == '\0' || len < 5 || len > 11
		|| ft_isdigit(rgb[0]) != 1 || check_rgb_syntax(rgb, len) != 0)
		return (-1);
	*color = malloc(sizeof(t_color));
	if (color == NULL)
		return (-1);
	while (j <= 2 && i < (int)ft_strlen(rgb))
	{
		len = 0;
		if (ft_isdigit(rgb[i]) == 1 && ++j < 3)
			len = rgb_atoi(*color, rgb + i, j);
		if (len == -1)
			return (-1);
		i += len + 1;
	}
	*flag = 1;
	return (0);
}

static char	*copy_texture_path(char *line)
{
	char	*temp;

	while (*line == ' ')
		line++;
	if (*line == '\0')
		return (NULL);
	temp = ft_strdup(line);
	if (temp == NULL)
		return (NULL);
	return (temp);
}

int	get_texture_paths(t_data *data)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (++i < data->info_lines_count)
	{
		if (ft_strncmp(data->file[i], "NO ", 3) == 0)
			data->texture_path_n = copy_texture_path(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "SO ", 3) == 0)
			data->texture_path_s = copy_texture_path(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "WE ", 3) == 0)
			data->texture_path_w = copy_texture_path(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "EA ", 3) == 0)
			data->texture_path_e = copy_texture_path(data->file[i] + 3);
		else if (ft_strncmp(data->file[i], "F ", 2) == 0)
			ret = get_rgb(&data->floor_color, data->file[i] + 2, &data->fc, 0);
		else if (ft_strncmp(data->file[i], "C ", 2) == 0)
			ret = get_rgb(&data->ceiling_col, data->file[i] + 2, &data->cc, 0);
		else if (data->file[i][0] != '\n')
			return (-1);
		if (ret != 0)
			return (-1);
	}
	return (0);
}
