#include "../includes/lem_in.h"

int analyze_map_data(t_list **input, t_farm *map)
{
	t_list *data;

	map->ants = NULL;
	map->start = NULL;
	map->end = NULL;
	map->rooms = NULL;
	map->turns = NULL;
	map->links = NULL;

	if (!handle_line_data(input))
		return (0);
	data = *input;
	if (!map || !data)
		return 0;
	if (!handle_ant_data(&data, map))
		return (0);
	if (!resolve_rooms(&data, map))
	 	return (0);
	if (!ft_read_connections(&data, map))
	 	return (0);
	return (1);
}
