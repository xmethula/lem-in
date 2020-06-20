#include "../includes/lem_in.h"

int				set_path(t_farm *farm, t_list *path,
					int *arrived)
{
    t_ant	*ant;
	t_list	*ant_list;
	t_list	*turn;

	ant_list = farm->ants;
	while (ant_list != NULL)
	{
		ant = (t_ant*)(ant_list->content);
		if (locate(ant, farm, path) == 1)
		{
            turn = find_turn(ant, ant->room);
			if (!turn)
				return (0);
			ft_lstappend(&(farm->turns), turn);
			if (ant->room == farm->end)
				(*arrived)++;
		}
		ant_list = ant_list->next;
	}
	((t_turn*)(turn->content))->last_move = 1;
	return (1);
}

int		is_link(t_list *data)
{
	size_t	size;
	char	**link;

	if (!data)
		return (0);
	if (!(link = ft_strsplit((char*)(data->content), '-')))
		return (0);
	size = ft_board_size(link);
	ft_clear_data(link);
	if (size < 2)
		return (0);
	return (1);
}

int		locate(t_ant *ant, t_farm *farm, t_list *path)
{
	t_room	*current_node;
	t_room	*next_node;

	if (!(ant->room))
		ant->room = farm->start;
	while (path->next != NULL)
	{
		current_node = (t_room*)(path->content);
		next_node = (t_room*)(path->next->content);
		if (ant->room == current_node &&
			(next_node->available || next_node == farm->end))
		{
			ant->room->available = 1;
			ant->room = next_node;
			ant->room->available = 0;
			return (1);
		}
		path = path->next;
	}
	return (0);
}

int		ft_negative(const char *str, size_t n)
{
	unsigned int	nbr;
	int				neg;

	while (ft_space(*str))
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else
	{
		neg = 0;
		if (*str == '+')
			str++;
	}
	nbr = 0;
	while (ft_isdigit(*str) && n--)
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (neg) ? -(int)nbr : (int)nbr;
}

size_t		get_listsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

int     ft_space(int x)
{
    if (x == ' ' || x == '\t' || x == '\n' 
    || x == '\v' || x == '\f' || x == '\r')
        return (1);
    return (0);
}

t_link	*ft_resolve_connection(t_room *from, t_room *to) //get link
{
	t_link	*connector;

	if (!(connector = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	connector->from = from;
	connector->to = to;
	return (connector);
}

t_room		*ft_room_name(t_list *rooms, char *name)
{
	t_room	*room;

	while (rooms != NULL)
	{
		room = (t_room*)(rooms->content);
		if (!ft_strcmp(room->name, name))
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}
