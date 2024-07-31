/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:31:41 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/30 16:35:33 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "stdio.h"

void	print_info(t_data *data)
{
	int	i;

	i = 0;
	printf("printing info");
	printf("path n: %s\n", data->texture_path_n);
	printf("path e: %s\n", data->texture_path_e);
	printf("path s: %s\n", data->texture_path_s);
	printf("path w: %s\n", data->texture_path_w);
	printf("ceiling color: ");
	while (i < 3)
	{
		printf("%d ", data->ceiling_color[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("floor color: ");
	while (i < 3)
	{
		printf("%d ", data->floor_color[i]);
		i++;
	}
	printf("\n");
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j].type != '\0')
		{
			printf("%c", data->map[i][j].type);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		while (data->file[i][j] != '\0')
		{
			printf("%c", data->file[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n printing map\n");
	print_map(data);
	print_info(data);
}
