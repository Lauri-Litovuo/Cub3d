#include "cubed_bonus.h"

long long	get_up_right_door_y(long long *t_coord, double *start_coord, double ray_angle)
{
	t_coord[1] = start_coord[1] - ((t_coord[0] - start_coord[0]) \
	* tan(convert_to_radians(90 - ray_angle)));
	if (t_coord[1] < 0)
		return (0);
	else
		return (t_coord[1]);
}

long long	get_down_right_door_y(t_data *data, long long *t_coord, double *start_coord, double ray_angle)
{
	t_coord[1] = start_coord[1] + ((t_coord[0] - start_coord[0]) \
	* tan(convert_to_radians(ray_angle - 90)));
	if (t_coord[1] >= ((data->map_height) * IMG_SIZE))
		return ((data->map_height - 1 * IMG_SIZE));
	else
		return (t_coord[1]);
}

long long	get_down_left_door_y(t_data *data, long long *t_coord, double *start_coord, double ray_angle)
{
	t_coord[1] = start_coord[1] + ((start_coord[0] - t_coord[0]) \
	* tan(convert_to_radians(270 - ray_angle)));
	if (t_coord[1] >= ((data->map_height) * IMG_SIZE))
		return ((data->map_height - 1) * IMG_SIZE);
	else
		return (t_coord[1]);
}

long long	get_up_left_door_y(long long *t_coord, double *start_coord, double ray_angle)
{
	t_coord[1] = start_coord[1] - ((start_coord[0] - t_coord[0]) \
	* tan(convert_to_radians(ray_angle - 270)));
	if (t_coord[1] < 0)
		return (0);
	else
		return (t_coord[1]);
}