#include "../includes/lem_in.h"

int				a_dijkstra(t_farm *farm)
{
	t_room	*cnode;
	t_list	*list;
	int		max;

	max = 2147483647 - 1;
	farm->start->dist = 0;
	list = get_room_list(farm);
    if (!list)
		return (0);
	while (list)
	{
		cnode = get_closest_node(list);
		ft_remove_list(&list, cnode, NULL);
		mod_nodes_dist(farm, cnode);
	}
    if (farm->end->dist != max)
        return (1);
    else
        return (0);
}

void		mod_nodes_dist(t_farm *farm, t_room *room)
{
	t_list	*links;
	t_link	*link;
	t_room	*to_room;

	links = farm->links;
	while (links)
	{
		link = (t_link*)(links->content);
		if (link->to == room)
			to_room = link->from;
		else if (link->from == room)
			to_room = link->to;
		else
			to_room = NULL;
		if (to_room && to_room != farm->start && to_room->dist > room->dist + 1)
		{
			to_room->dist = room->dist + 1;
			to_room->prev = room;
		}
		links = links->next;
	}
}

t_room	*get_closest_node(t_list *rooms)
{
    int     min_dist;
	t_room	*node;

	node = (t_room*)(rooms->content);
	rooms = rooms->next;
    min_dist = node->dist;
	while (rooms)
	{
		if (min_dist > ((t_room*)(rooms->content))->dist)
		{
			node = (t_room*)(rooms->content);
			min_dist = node->dist;
		}
		rooms = rooms->next;
	}
	return (node);
}

t_list	*get_room_list(t_farm *farm)
{
	t_list	*room_list;
	t_list	*temp;
	t_list	*list;

	room_list = NULL;
	list = farm->rooms;
	while (list)
	{
		if (!(temp = ft_lstcpy(list->content, sizeof(t_room))))
		{
			ft_lstdel(&room_list, NULL);
			return (NULL);
		}
		ft_lstappend(&room_list, temp);
		list = list->next;
	}
	return (room_list);
}

t_list			*run_a_dijkstra(t_farm *farm)
{
	t_list	*path;
	t_list	*list;
    t_room	*node;
    size_t  limit;

    limit = 2;
	path = NULL;
    if (a_dijkstra(farm) == 0)
		return (NULL);
	node = farm->end;
	while (node != NULL)
	{
		if (!(list = ft_lstcpy(node, sizeof(t_room))))
		{
			ft_lstdel(&path, NULL);
			return (NULL);
		}
		ft_lstadd(&path, list);
		node = node->prev;
	}
	if (get_listsize(path) < limit)
		ft_lstdel(&path, NULL);
	return (path);
}