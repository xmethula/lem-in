#include "../includes/lem_in.h"

static int	set_coordinates(char *str, t_room *room)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(str) - 1;
	while (size > 0 && !ft_space(str[size]))
	{
		size--;
		i++;
	}
	if (!ft_space(str[size]) || !size || !i)
		return (0);
	room->y = ft_negative(str + size, i);
	i = 0;
	size--;
	while (size > 0 && !ft_space(str[size]))
	{
		size--;
		i++;
	}
	if (!ft_space(str[size]) || !size || !i)
		return (0);
	room->x = ft_negative(str + size, i);
	return (1);
}

static int	set_name(char *str, t_room *r)
{
	size_t	size;
	size_t	spaces;

	size = ft_strlen(str) - 1;
	spaces = 0;
	while (size != 0)
	{
		if (ft_space(str[size]))
			spaces++;
		if (spaces == 2)
			break ;
		size--;
	}
	if (spaces != 2)
		return (0);
	if (!(r->name = ft_strnew(size)))
		return (0);
	ft_strncpy(r->name, str, size);
	return (1);
}

t_room		*resolve_info(char *str)
{
	t_room	*r;
	int		max;

	max = 2147483647 - 1;
	if (!(r = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!set_coordinates(str, r) || !set_name(str, r) ||
		!ft_strlen(r->name) || r->name[0] == 'L' ||
		r->name[0] == '#')
	{
		free(r);
		return (NULL);
	}
	r->dist = max;
	r->available = 1;
	r->prev = NULL;
	return (r);
}

static int      add_rooms(t_room *r, t_farm *f)
{
    t_list *n;

    if (!(n = ft_lstcpy(r, sizeof(t_room))))
    {
        ft_free(r, sizeof(t_room));
        return (0);
    }
    ft_lstappend(&(f->rooms), n);
    return (1);
}

int			resolve_room(t_list **data, t_farm *f)
{
    int cmd;
    t_room  *r;

    if ((cmd = get_cmd(*data)) != -1 && 
            ((cmd == START_COMMAND && !(f->start)) || 
             (cmd == END_COMMAND && !(f->end))))
        *data = (*data)->next;
    if (is_link(*data))
        return (1);
	if (!(*data) || !(r = resolve_info((char*)((*data)->content)))
		|| !add_rooms(r, f) ||
		(cmd == START_COMMAND && f->start) ||
		(cmd == END_COMMAND && f->end))
		return (0);
	if (cmd == START_COMMAND && !(f->start))
		f->start = r;
	else if (cmd == END_COMMAND && !(f->end))
		f->end = r;
	if (find_info(f, r))
		return (0);
	return (1);
}

int		resolve_rooms(t_list **data, t_farm *f)
{
	while (*data)
	{
		if (ignore_comments(data) || ignore_commands(data))
			continue ;
		if (!resolve_room(data, f))
			return (0);
		if (is_link(*data))
			break ;
		*data = (*data)->next;
	}
	if (f->start == NULL || f->end == NULL)
		return (0);
	return (*data != NULL);
}