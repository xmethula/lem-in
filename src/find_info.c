#include "../includes/lem_in.h"

static int	is_info_same(t_room *rm1, t_room *rm2)
{
	if (rm1 && rm1 != rm2 && 
            (!ft_strcmp(rm1->name, rm2->name) || 
             (rm1->x == rm2->x && rm1->y == rm2->y)))
        return (1);
    return (0);
}

int     find_info(t_farm *f, t_room *r)
{
    t_list *s;

    s = f->rooms;
    while (s)
    {
        if (is_info_same((t_room*)(s->content), r))
            return (1);
        s = s->next;
    }
    return (0);
}

int     find_path(t_farm *farm)
{
    t_list  *path;
    int     i;

    path = run_a_dijkstra(farm);
    if (!path)
		return (0);
	i = 0;
	while (i < farm->n_ants)
        if (!set_path(farm, path, &i))
			break ;
	ft_lstdel(&path, NULL);
    if (i == farm->n_ants)
	    return (1);
    else
        return (0);
}

t_list	*find_turn(t_ant *ant, t_room *room)
{
	t_list	*turn_list;
	t_turn	*turn;

    turn = (t_turn*)malloc(sizeof(t_turn));
	if (!turn)
		return (NULL);
	turn->ant = ant;
	turn->room = room;
	turn->last_move = 0;
	turn_list = ft_lstcpy(turn, sizeof(t_turn));
    if (!turn_list)
		free(turn);
	return (turn_list);
}

size_t		ft_board_size(char **board)
{
	size_t i;

	i = 0;
    if(!board)
        return 0;
    else
       while (board[i] != NULL)
			i++;
	return (i);
}

t_list		*ft_lstcpy(void *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	res->content = content;
	res->content_size = content_size;
	res->next = NULL;
	return (res);
}