#include "../includes/lem_in.h"

int		ft_connections_to_the_rooms(t_list *input, t_farm *farm,
							t_room **from, t_room **to)
{
	char	**connector;

    connector = ft_strsplit((char*)(input->content), '-');
    *from = ft_room_name(farm->rooms, connector[0]);
    *to = ft_room_name(farm->rooms, connector[1]);
	if (!connector)
		return (0);
	if (!(*from) || !(*to) || (*from) == (*to))
	{
		ft_clear_data(connector);
		return (0);
	}
	ft_clear_data(connector);
	return (1);
}

int				ft_read_connection(t_list *input, t_farm *farm) //parse link
{
	t_list	*new_list;
	t_link	*connection;
	t_room	*from;
	t_room	*to;
    int     rooms_connector;

    rooms_connector = ft_connections_to_the_rooms(input, farm, &from, &to);
    connection = ft_resolve_connection(from, to);
    new_list = ft_lstcpy(connection, sizeof(t_link));
	if (!(rooms_connector) || !(connection))
		return (0);
	if (!(new_list))
	{
		free(connection);
		return (0);
	}
	ft_lstappend(&(farm->links), new_list);
	return (1);
}

int		ft_read_connections(t_list **input, t_farm *farm) //parse links
{
	while (*input != NULL)
	{
		if (ignore_comments(input) || ignore_commands(input))
			continue ;
		if (!(*input))
			return (1);
        if (!is_link(*input) || !ft_read_connection(*input, farm))
			return (0);
		*input = (*input)->next;
	}
	if (*input == NULL)
		return (1);
	return (0);
}