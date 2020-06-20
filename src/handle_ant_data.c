#include "../includes/lem_in.h"

int ft_isinteger(char *line)
{
	int num;
	char *itoa;
	int result;

	num = ft_atoi(line);
	itoa = ft_itoa(num);
	if (ft_strequ(itoa, line))
		result = 1;
	else
		result = 0;
	ft_strdel(&itoa);
	return (result);
}

int check_data(t_list **data)
{
	while (*data)
	{
		if (ignore_comments(data) || ignore_commands(data))
			continue;
		break;
	}
	if ((*data) == 0)
		return (0);
	return(1);
}

static int analyze_no_of_ants(t_list **data, t_farm *map)
{
	char *num;

	check_data(data);
	num = (char *)((*data)->content);
	map->n_ants = (int)ft_atoi(num);
	if (ft_isinteger(num) == 0 || map->n_ants <= 0)
		return (0);
	*data = (*data)->next;
	return (1);
}

static t_list *create_ant(int ant_id)
{
	t_list *new_list;
	t_ant *ant;

	if ((ant = (t_ant *)malloc(sizeof(t_ant))) == 0)
		return (NULL);
	ant->room = NULL;
	ant->id = ant_id;
	if ((new_list = ft_lstcpy(ant, sizeof(t_ant))) == 0)
		free(ant);
	return (new_list);
}

int handle_ant_data(t_list **data, t_farm *map)
{
	t_list *new;
	int ant_id;

	if (analyze_no_of_ants(data, map) == 0)
	{
		return (0);
	}
	ant_id = 0;
	while (++ant_id <= map->n_ants)
	{
		if ((new = create_ant(ant_id)) == 0)
		{
			ft_lstdel(&(map->ants), ft_struct_del);
			return (0);
		}
		ft_lstappend(&(map->ants), new);
	}
	return (1);
}
