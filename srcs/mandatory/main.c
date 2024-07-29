/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:17:31 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/22 11:17:37 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->map = NULL;
	data->wall_img_n = NULL;
	data->wall_img_w = NULL;
	data->wall_img_s = NULL;
	data->wall_img_w = NULL;
	data->v_h_flag = -1;
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Please give one map (.cub -file) as an argument", 2);
		return (1);
	}

	data = malloc(sizeof(t_data));
	if (data == NULL)
		sys_error_exit(data, "Malloc failed", 0);

	init_data(data);
	get_map(data, argv[1]);
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", false);

	if (!data->mlx)
		error_exit(data, mlx_strerror(mlx_errno), 0);
	get_images(data);

	data->player_coord[0] = 2 * IMG_SIZE - 1; // TEST
    data->player_coord[1] = 2 * IMG_SIZE - 1; // TEST
	data->player_angle = 120; // TEST
	
	data->fl_colour = get_rgba(77, 71, 58, 255); // TEST
	data->ceil_colour = get_rgba(18, 17, 16, 255); // TEST

	draw_image(data);

	if (mlx_image_to_window(data->mlx, data->game_img, 0, 0) < 0)
		error_exit(data, mlx_strerror(mlx_errno), 1);

	mlx_key_hook(data->mlx, &keyhook, (void*)data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	print_goodbye_message();
	free_data(data);
	return (0);
}
