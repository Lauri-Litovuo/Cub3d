#include "cubed_bonus.h"

long long	get_up_right_y(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[1] = p_coord[1] - ((t_coord[0] - p_coord[0]) \
	* tan(convert_to_radians(90 - ray_angle)));
	if (t_coord[1] < 0)
		return (0);
	else
		return (t_coord[1] / IMG_SIZE);
}

long long	get_down_right_y(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[1] = p_coord[1] + ((t_coord[0] - p_coord[0]) \
	* tan(convert_to_radians(ray_angle - 90)));
	if (t_coord[1] >= ((data->map_height) * IMG_SIZE))
		return (data->map_height - 1);
	else
		return (t_coord[1] / IMG_SIZE);
}

long long	get_down_left_y(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[1] = p_coord[1] + ((p_coord[0] - t_coord[0]) \
	* tan(convert_to_radians(270 - ray_angle)));
	if (t_coord[1] >= ((data->map_height) * IMG_SIZE))
		return (data->map_height - 1);
	else
		return (t_coord[1] / IMG_SIZE);
}

long long	get_up_left_y(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[1] = p_coord[1] - ((p_coord[0] - t_coord[0]) \
	* tan(convert_to_radians(ray_angle - 270)));
	if (t_coord[1] < 0)
		return (0);
	else
		return (t_coord[1] / IMG_SIZE);
}