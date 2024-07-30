/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:31:41 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/29 18:33:53 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	print_data(t_data *data)
{
	int i;
	int j;

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
}

void	print_map(t_data *data)
{
	int i;
	int j;

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
